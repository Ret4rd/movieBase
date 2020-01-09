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
('��� ������'),
('���� �������'),
('������ ����'),
('������ �� ����'),
('���� ����'),
('������ ��� �����'),
('��� ����'),
('�������� �� ������'),
('���� �������'),
('������� ������������'),
('��������� ��������'),
('��� ������'),
('������ ������'),
('������ ���������'),
('������ ���������'),
('��� �������'),
('���� ������'),
('��� ������'),
('����� �������'),
('���� ������'),
('��� �����'),
('������ ����'),
('��� ����'),
('���� ����'),
('������ ����� �������'),
('��� �������'),
('���� �������'),
('���� ��������'),
('����� �����'),
('�������� ���������'),
('������ ������'),
('��� ������'),
('������� �������'),
('��� ����'),
('����� ������ �������'),
('������ �������'),
('����� �������'),
('���� ������')
GO

INSERT Directors
(fullName)
VALUES
('������ ��������'),
('������ ��������'),
('������ �����'),
('��� ����� ��������'),
('����� ������'),
('������ �����'),
('��� �������'),
('������� ���� �������'),
('����� �����'),
('������ �������'),
('������ �������'),
('��������� �����')
GO

INSERT Movies
(nameMovie, idDirector)
VALUES
('������', 4),
('�����', 4),
('��������', 4),
('���� � ����� ����', 4),
('�������', 1),
('������� �����', 1),
('������', 1),
('���� � ����-�����', 1),
('��������', 1),
('������� ���', 1),
('����� ���-�����', 1),
('��� ������', 1),
('����������', 1),
('������ ���� ,���� �������', 2),
('������ ��������', 2),
('������ ������', 2),
('������� �����', 2),
('�������� �����', 3),
('������������ ����', 5),
('������� ��������', 6),
('����� ��������� �����', 6),
('������� �������', 7),
('�������� ����', 8),
('����������� �������', 8),
('���������', 9),
('��������', 9),
('������������ ���', 9),
('����������', 10),
('���������� 2', 10),
('�������', 10),
('������ ����', 11),
('�����', 11),
('����� � �������', 11),
('�����', 12),
('�������', 12),
('������', 12),
('������ ������', 12)
GO

INSERT Directors
(fullName)
VALUES
('��� ����')
GO

INSERT Directors
(fullName)
VALUES
('��� ������')
GO

INSERT Actors
(fullName)
VALUES
('���� �������'),
('����� ����'),
('���� ��������'),
('���� �����'),
('���� �����'),
('�������� ����'),
('���� ������'),
('������ ������'),
('����� ���� ����'),
('��������� �����'),
('��� ����'),
('�������� ����'),
('��� �����'),
('��������� ��������')
GO

INSERT Movies
(nameMovie, idDirector)
VALUES
('�����, ������, ��� ������', 13),
('������� ���', 13),
('���������', 13),
('���� ������', 14)
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