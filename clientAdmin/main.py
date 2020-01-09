import sys
from mainwindow import *
from PyQt5 import QtCore, QtGui, QtWidgets, QtSql
from PyQt5.QtWidgets import QMessageBox
from PyQt5.Qt import QTableView, QInputDialog, QModelIndex, QHeaderView


class MyWin(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        db = QtSql.QSqlDatabase.addDatabase("QODBC")
        db.setDatabaseName("DRIVER={SQL SERVER};SERVER=LAPTOP-0R0CFR1B;DATABASE=courseWork;Trusted_Connection=yes;")
        db.open()
        if (not(db.open())):
            QMessageBox.warning(0, "Ошибка", "Не удалось подключиться к базе данных")

        self.ui.cBTable.addItem("Фильмы")
        self.ui.cBTable.addItem("Режиссеры")
        self.ui.cBTable.addItem("Актеры")


        self.ui.btAdd.clicked.connect(self.onClickAdd)
        self.ui.btDelete.clicked.connect(self.onClickDelete)
        self.ui.btUpdate.clicked.connect(self.onIndexChange)
        self.ui.cBTable.currentIndexChanged.connect(self.onIndexChange)
        self.ui.btEdit.clicked.connect(self.onClickEdit)

        self.ui.tableView.horizontalHeader().setStretchLastSection(1)
        query = QtSql.QSqlQuery()
        query.prepare("SELECT* FROM getMovieView")
        query.exec()
        model = QtSql.QSqlQueryModel()
        model.setQuery(query)

        self.ui.tableView.setModel(model)


    def onIndexChange(self):
        if(self.ui.cBTable.currentIndex() == 0):
            query = QtSql.QSqlQuery()
            query.prepare("SELECT* FROM getMovieView")
            query.exec()
            model = QtSql.QSqlQueryModel()
            model.setQuery(query)
            self.ui.tableView.setModel(model)

        if(self.ui.cBTable.currentIndex() == 1):
            query = QtSql.QSqlQuery()
            query.prepare("SELECT fullName as Режисеры FROM Directors")
            query.exec()
            model = QtSql.QSqlQueryModel()
            model.setQuery(query)
            self.ui.tableView.setModel(model)

        if (self.ui.cBTable.currentIndex() == 2):
            query = QtSql.QSqlQuery()
            query.prepare("SELECT fullName as Актеры FROM Actors")
            query.exec()
            model = QtSql.QSqlQueryModel()
            model.setQuery(query)
            self.ui.tableView.setModel(model)


    def onClickAdd(self):
        if (self.ui.cBTable.currentIndex() == 0):
            filmName, ok = QInputDialog.getText(self, 'Добавление записи','Введите название фильма')
            if (not(ok)):
                return
            DirectorName, ok = QInputDialog.getText(self, 'Добавление записи', 'Введите имя режиссера')
            if (not (ok)):
                return
            ActorsName, ok = QInputDialog.getText(self, 'Добавление записи', 'Введите имена актеров через запятую')
            if (not (ok)):
                return

            query = QtSql.QSqlQuery()
            query.prepare("{CALL createMovieRecord(?, ?)}")
            query.bindValue(0, filmName)
            query.bindValue(1, DirectorName)
            query.exec()

            actorsNameList = ActorsName.split(', ')
            for actorName in actorsNameList:
                query.prepare("{CALL createActorsRecord(?, ?)}")
                query.bindValue(0, filmName)
                query.bindValue(1, actorName)
                query.exec()

        if (self.ui.cBTable.currentIndex() == 1):
            directorName, ok = QInputDialog.getText(self, 'Добавление записи', 'Введите имя режиссера')
            if (not (ok)):
                return
            query = QtSql.QSqlQuery()
            query.prepare("{CALL addDirector(?)}")
            query.bindValue(0, directorName)
            query.exec()

        if (self.ui.cBTable.currentIndex() == 2):
            actorName, ok = QInputDialog.getText(self, 'Добавление записи', 'Введите имя актера')
            if (not (ok)):
                return
            query = QtSql.QSqlQuery()
            query.prepare("{CALL addActor(?)}")
            query.bindValue(0, actorName)
            query.exec()

    def onClickDelete(self):
        if (self.ui.cBTable.currentIndex() == 0):
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  2, QModelIndex())
            actorsName = self.ui.tableView.model().data(ind)
            actorsNameList = actorsName.split(', ')
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            query = QtSql.QSqlQuery()
            for actorNameStr in actorsNameList:
                query.prepare("{CALL deleteActorsMovie(?, ?)}")
                query.bindValue(0, self.ui.tableView.model().data(ind))
                query.bindValue(1, actorNameStr)
                query.exec()

            query.prepare("{CALL deleteMovie(?)}")
            query.bindValue(0, self.ui.tableView.model().data(ind))
            query.exec()

        if (self.ui.cBTable.currentIndex() == 1):
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            query = QtSql.QSqlQuery()
            query.prepare("{CALL deleteDirector(?)}")
            query.bindValue(0, self.ui.tableView.model().data(ind))
            query.exec()

        if (self.ui.cBTable.currentIndex() == 2):
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            query = QtSql.QSqlQuery()
            query.prepare("{CALL deleteActor(?)}")
            query.bindValue(0, self.ui.tableView.model().data(ind))
            query.exec()

    def onClickEdit(self):
        if (self.ui.cBTable.currentIndex() == 0):
            indMovie = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            oldMovieName = self.ui.tableView.model().data(indMovie)
            indDirector = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                       1, QModelIndex())
            oldDirectorName = self.ui.tableView.model().data(indDirector)
            indActors = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                       2, QModelIndex())
            oldActorsName = self.ui.tableView.model().data(indActors)
            if(self.ui.tableView.currentIndex() == indMovie):
                movieName, ok = QInputDialog.getText(self, 'Редактирование', 'Введите название фильма')
                if (not (ok)):
                    return
                query = QtSql.QSqlQuery()
                query.prepare("{CALL editMovie(?, ?)}")
                query.bindValue(0, oldMovieName)
                query.bindValue(1, movieName)
                query.exec()
            if (self.ui.tableView.currentIndex() == indDirector):
                directorName, ok = QInputDialog.getText(self, 'Редактирование', 'Введите имя режиссера')
                if (not (ok)):
                    return
                query = QtSql.QSqlQuery()
                query.prepare("{CALL editMovieDirector(?, ?)}")
                query.bindValue(0, directorName)
                query.bindValue(1, oldMovieName)
                query.exec()

            if (self.ui.tableView.currentIndex() == indActors):
                actorsName, ok = QInputDialog.getText(self, 'Редактирование', 'Введите имя актеров через запятую')
                if (not (ok)):
                    return
                query = QtSql.QSqlQuery()
                actorsNameList = oldActorsName.split(', ')
                for actorNameStr in actorsNameList:
                    query.prepare("{CALL deleteActorsMovie(?, ?)}")
                    query.bindValue(0, oldMovieName)
                    query.bindValue(1, actorNameStr)
                    query.exec()

                actorsNameList = actorsName.split(', ')
                for actorNameStr in actorsNameList:
                    query.prepare("{CALL editMovieActors(?, ?, ?)}")
                    query.bindValue(0, actorNameStr)
                    query.bindValue(1, oldActorsName)
                    query.bindValue(2, oldMovieName)
                    query.exec()

        if (self.ui.cBTable.currentIndex() == 1):
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            directorName, ok = QInputDialog.getText(self, 'Редактирование', 'Введите имя режиссера')
            if (not (ok)):
                return
            query = QtSql.QSqlQuery()
            query.prepare("{CALL editDirector(?, ?)}")
            query.bindValue(0, self.ui.tableView.model().data(ind))
            query.bindValue(1, directorName)
            query.exec()

        if (self.ui.cBTable.currentIndex() == 2):
            ind = self.ui.tableView.model().index(self.ui.tableView.currentIndex().row(),
                                                  0, QModelIndex())
            actorName, ok = QInputDialog.getText(self, 'Редактирование', 'Введите имя актера')
            if (not (ok)):
                return
            query = QtSql.QSqlQuery()
            query.prepare("{CALL editActor(?, ?)}")
            query.bindValue(0, self.ui.tableView.model().data(ind))
            query.bindValue(1, actorName)
            query.exec()

if __name__=="__main__":
    app = QtWidgets.QApplication(sys.argv)
    myapp = MyWin()
    myapp.show()
    sys.exit(app.exec_())