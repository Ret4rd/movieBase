# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(586, 452)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.cBTable = QtWidgets.QComboBox(self.centralwidget)
        self.cBTable.setEditable(False)
        self.cBTable.setCurrentText("")
        self.cBTable.setObjectName("cBTable")
        self.horizontalLayout.addWidget(self.cBTable)
        self.btAdd = QtWidgets.QPushButton(self.centralwidget)
        self.btAdd.setObjectName("btAdd")
        self.horizontalLayout.addWidget(self.btAdd)
        self.btDelete = QtWidgets.QPushButton(self.centralwidget)
        self.btDelete.setObjectName("btDelete")
        self.horizontalLayout.addWidget(self.btDelete)
        self.btEdit = QtWidgets.QPushButton(self.centralwidget)
        self.btEdit.setObjectName("btEdit")
        self.horizontalLayout.addWidget(self.btEdit)
        self.btUpdate = QtWidgets.QPushButton(self.centralwidget)
        self.btUpdate.setObjectName("btUpdate")
        self.horizontalLayout.addWidget(self.btUpdate)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.tableView = QtWidgets.QTableView(self.centralwidget)
        self.tableView.setObjectName("tableView")
        self.verticalLayout.addWidget(self.tableView)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 586, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btAdd.setText(_translate("MainWindow", "Добавить"))
        self.btDelete.setText(_translate("MainWindow", "Удалить"))
        self.btEdit.setText(_translate("MainWindow", "Редактировать"))
        self.btUpdate.setText(_translate("MainWindow", "Обновить"))
