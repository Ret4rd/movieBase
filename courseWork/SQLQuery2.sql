CREATE TABLE Client
(id int NOT NULL IDENTITY,
firstName varchar(32) NOT NULL,
secondName varchar(32) NULL,
loginClient nvarchar(32) NOT NULL,
passwordClient varchar(32) NOT NULL,
idFavoriteMovie int,
idFavoriteDirector int,
idFavoriteActor int,
PRIMARY KEY(id),
FOREIGN KEY(idFavoriteMovie) REFERENCES Movies(id),
FOREIGN KEY(idFavoriteDirector) REFERENCES Directors(id),
FOREIGN KEY(idFavoriteActor) REFERENCES Actors(id),
UNIQUE(loginClient)
)
GO

CREATE TABLE Movies
(
id int NOT NULL IDENTITY,
nameMovie varchar(32),
idDirector int,
PRIMARY KEY(id),
FOREIGN KEY(idDirector) REFERENCES Directors(id)
)
GO

ALTER TABLE Movies
ADD
FOREIGN KEY(idDirector) REFERENCES Directors(id)
ON DELETE CASCADE
GO

CREATE TABLE Directors
(
id int NOT NULL IDENTITY,
fullName varchar(64),
PRIMARY KEY(id)
)
GO

CREATE TABLE ClientRatings
(
id int NOT NULL IDENTITY,
rating int,
idMovie int,
idClient int,
PRIMARY KEY(id),
FOREIGN KEY(idMovie) REFERENCES Movies(id),
FOREIGN KEY(idClient) REFERENCES Client(id)
)
GO

ALTER TABLE ClientRatings
ADD
FOREIGN KEY(idMovie) REFERENCES Movies(id)
ON DELETE CASCADE,
FOREIGN KEY(idClient) REFERENCES Client(id)
ON DELETE CASCADE
GO

CREATE TABLE Actors
(
id int NOT NULL IDENTITY,
fullName varchar(64),
PRIMARY KEY(id)
)
GO

CREATE TABLE ActorsMovies
(
id int NOT NULL IDENTITY,
idActor int,
idMovie int,
PRIMARY KEY(idActor, idMovie),
FOREIGN KEY(idActor) REFERENCES Actors(id),
FOREIGN KEY(idMovie) REFERENCES Movies(id)
)
GO

ALTER TABLE ActorsMovies
ADD
FOREIGN KEY(idActor) REFERENCES Actors(id)
ON DELETE CASCADE,
FOREIGN KEY(idMovie) REFERENCES Movies(id)
ON DELETE CASCADE
GO

ALTER TABLE Movies
ADD
averageRating int NULL
GO

INSERT Actors
(fullName)
VALUES
('Аль Пачино'),
('Адам Драйвер'),
('Рассел Кроу'),
('Роберт Де Ниро'),
('Брэд Питт'),
('Дэниел Дэй Льюис'),
('Шон Пенн'),
('Леонардо Ди Каприо'),
('Тоби Магуайр'),
('Арнольд Шварценеггер'),
('Сильвестр Сталлоне'),
('Хит Леджер'),
('Хоакин Феникс'),
('Мэттью Макконахи'),
('Дензел Вашингтон'),
('Тим Роббинс'),
('Мэтт Деймон'),
('Бен Аффлек'),
('Робин Уильямс'),
('Брюс Уиллис'),
('Том Хэнкс'),
('Джонни Депп'),
('Том Круз'),
('Джек Блэк'),
('Роберт Дауни Младший'),
('Бен Стиллер'),
('Адам Сэндлер'),
('Вупи Голдберг'),
('Мэрил Стрип'),
('Скарлетт Йоханссон'),
('Николь Кидман'),
('Рэй Лиотта'),
('Джейсон Стэтхем'),
('Джо Пеши'),
('Филип Сеймур Хоффман'),
('Дастин Хоффман'),
('Джефф Бриджес'),
('Джон Гудмен')
GO

INSERT Directors
(fullName)
VALUES
('Мартин Скорсезе'),
('Стивен Спилберг'),
('Джордж Лукас'),
('Пол Томас Андерсон'),
('Клинт Иствуд'),
('Братья Коэны'),
('Бен Стиллер'),
('Френсис Форд Коппола'),
('Ридли Скотт'),
('Джеймс Кэмерон'),
('Роберт Земекис'),
('Кристофер Нолан')
GO

INSERT Movies
(nameMovie, idDirector)
VALUES
('Мастер', 4),
('Нефть', 4),
('Магнолия', 4),
('Ночи в стиле буги', 4),
('Таксист', 1),
('Славные Парни', 1),
('Казино', 1),
('Волк С Уолл-Стрит', 1),
('Ирландец', 1),
('Бешеный Бык', 1),
('Банды Нью-Йорка', 1),
('Мыс страха', 1),
('Отступники', 1),
('Поймай меня ,если сможешь', 2),
('Список Шиндлера', 2),
('Особое мнение', 2),
('Индиана Джонс', 2),
('Звездные Войны', 3),
('Таинственная река', 5),
('Большой Лебовски', 6),
('После прочтения сжечь', 6),
('Солдаты неудачи', 7),
('Крестный Отец', 8),
('Апокалипсис сегодня', 8),
('Гладиатор', 9),
('Гангстер', 9),
('Совокупность лжи', 9),
('Терминатор', 10),
('Терминатор 2', 10),
('Титаник', 10),
('Форест Гамп', 11),
('Изгой', 11),
('Назад в будущее', 11),
('Помни', 12),
('Престиж', 12),
('Начало', 12),
('Темный рыцарь', 12)
GO

INSERT Directors
(fullName)
VALUES
('Гай Ричи')
GO

INSERT Directors
(fullName)
VALUES
('Рон Ховард')
GO

INSERT Actors
(fullName)
VALUES
('Марк Уолберг'),
('Джона Хилл'),
('Джек Николсон'),
('Лиам Нисон'),
('Рэйф Файнс'),
('Харрисон Форд'),
('Марк Хэммил'),
('Марлон Брандо'),
('Майкл Джей Фокс'),
('Кристофер Ллойд'),
('Гай Пирс'),
('Кристиан Бэйл'),
('Том Харди'),
('Дженнифер Коннелли')
GO

INSERT Movies
(nameMovie, idDirector)
VALUES
('Карты, деньги, два ствола', 13),
('Большой Куш', 13),
('Револьвер', 13),
('Игры разума', 14)
GO

INSERT ActorsMovies
(idActor, idMovie)
VALUES
(13,1),
(35,1),
(6,2),
(23,3),
(35,3),
(39,4),
(35,4),
(4,5),
(4,6),
(34,6),
(32,6),
(4,7),
(34,7),
(8,8),
(40,8),
(4,9),
(1,9),
(34,9),
(4,10),
(34,10),
(8,11),
(6,11),
(4,12),
(8,13),
(17,13),
(39,13),
(41,13),
(8,14),
(21,14),
(42,15),
(43,15),
(23,16),
(44,17),
(45,18),
(44,18),
(7,19),
(16,19),
(37,20),
(38,20),
(5,21),
(14,22),
(23,22),
(24,22),
(25,22),
(26,22),
(1,23),
(46,23),
(46,24),
(3,25),
(13,25),
(3,26),
(15,26),
(3,27),
(8,27),
(10,28),
(10,29),
(8,30),
(21,31),
(21,32),
(47,33),
(48,33),
(49,34),
(50,35),
(8,36),
(51,36),
(50,37),
(12,37),
(33,38),
(33,39),
(5,39),
(33,40),
(32,40),
(3,41),
(52,41)
GO

SELECT* FROM Client
SELECT* FROM Directors
SELECT* FROM Movies
SELECT* FROM Actors
SELECT* FROM ActorsMovies
SELECT* FROM ClientRatings

/*DELETE FROM Actors
WHERE id > 1009;*/