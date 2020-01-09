-- ================================================
-- Template generated from Template Explorer using:
-- Create Procedure (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the procedure.
-- ================================================
/*SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE <Procedure_Name, sysname, ProcedureName> 
	-- Add the parameters for the stored procedure here
	<@Param1, sysname, @p1> <Datatype_For_Param1, , int> = <Default_Value_For_Param1, , 0>, 
	<@Param2, sysname, @p2> <Datatype_For_Param2, , int> = <Default_Value_For_Param2, , 0>
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT <@Param1, sysname, @p1>, <@Param2, sysname, @p2>
END
GO*/

USE courseWork;
GO
CREATE OR ALTER PROCEDURE regAccount(
@firstName VARCHAR(32),
@secondName VARCHAR(32),
@Login VARCHAR(32),
@Password VARCHAR(32)
)
AS
DECLARE @existsLogin INTEGER;
DECLARE @myId INTEGER;
BEGIN
	SELECT @existsLogin = COUNT(id) FROM Client WHERE loginClient = @Login;
	IF (@existsLogin > 0)
	BEGIN
		RAISERROR ('Пользователь с таким логином уже существует', 16, 1);
	END;
	INSERT INTO Client(firstName, secondName, loginClient, passwordClient)
	VALUES(@firstName, @secondName, @Login, @Password);
	SELECT id as myId FROM Client WHERE loginClient = @Login;
	RETURN @myId;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE loginAccount(
@Login VARCHAR(32),
@Password VARCHAR(32)
)
AS
DECLARE @myId INTEGER;
BEGIN
	SELECT @myId = id FROM Client WHERE loginClient = @Login 
						AND passwordClient = @Password;
						
		if (COUNT(@myId) != 1) 
		BEGIN
			RAISERROR('Вы неверно ввели логин или пароль', 16, 1);
		END;
	SELECT Client.id, firstName, loginClient, passwordClient
	FROM Client WHERE (Client.id = @myId)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getSecondName(
@myId INTEGER
)
AS
BEGIN
	SELECT secondName FROM Client
	WHERE (Client.id = @myId) AND (secondName IS NOT NULL)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getFavMovie(
@myId INTEGER
)
AS
BEGIN
	SELECT nameMovie FROM Client, Movies
	WHERE (Client.id = @myId) AND (idFavoriteMovie IS NOT NULL) AND (idFavoriteMovie = Movies.id)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getFavActor(
@myId INTEGER
)
AS
BEGIN
	SELECT fullName FROM Client, Actors
	WHERE (Client.id = @myId) AND (idFavoriteActor IS NOT NULL) AND (idFavoriteActor = Actors.id)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getFavDirector(
@myId INTEGER
)
AS
BEGIN
	SELECT fullName FROM Client, Directors
	WHERE (Client.id = @myId) AND (idFavoriteDirector IS NOT NULL) AND (idFavoriteDirector = Directors.id)
END;
GO

SELECT * FROM Client

USE courseWork;
GO
CREATE OR ALTER PROCEDURE updateAccount(
@firstName VARCHAR(32),
@secondName VARCHAR(32),
@Login VARCHAR(32),
@Password VARCHAR(32)
)
AS
BEGIN
	UPDATE Client SET firstName = @firstName, secondName = @secondName, passwordClient = @Password
			WHERE loginClient = @Login;
END;
GO

USE courseWork
GO
CREATE OR ALTER VIEW getMovieView
AS
	SELECT Movies.nameMovie AS Фильм, Directors.fullName as Режиссер , STRING_AGG(Actors.fullName, ', ') as Актеры
	FROM Movies INNER JOIN Directors ON Movies.idDirector = Directors.id
	INNER JOIN (Actors INNER JOIN ActorsMovies ON Actors.id = ActorsMovies.idActor) ON Movies.id = ActorsMovies.idMovie 
	GROUP BY nameMovie, Directors.fullName
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getMovie
AS
BEGIN
	SELECT* FROM getMovieView
END;
GO

USE courseWork
GO
CREATE OR ALTER VIEW findMovieView
AS
	SELECT Movies.nameMovie, Directors.fullName , STRING_AGG(Actors.fullName, ', ') as actors, averageRating 
	FROM Movies INNER JOIN Directors ON Movies.idDirector = Directors.id
	INNER JOIN (Actors INNER JOIN ActorsMovies ON Actors.id = ActorsMovies.idActor) ON Movies.id = ActorsMovies.idMovie 
	GROUP BY nameMovie, Directors.fullName, averageRating 
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE findMovie(
@movieName VARCHAR(32)
)
AS
BEGIN
	SELECT* FROM findMovieView
	WHERE @movieName = nameMovie
END;
GO

USE courseWork
GO
CREATE VIEW getActorsView
AS
	SELECT Actors.fullName as ActorsName, STRING_AGG(nameMovie, ', ') as MoviesName
	FROM Movies INNER JOIN (Actors INNER JOIN ActorsMovies ON Actors.id = ActorsMovies.idActor) ON Movies.id = ActorsMovies.idMovie
	GROUP BY Actors.fullName
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getActors
AS
BEGIN
	SELECT * FROM getActorsView
END;
GO

USE courseWork
GO
CREATE OR ALTER VIEW getDirectorsView
AS
	SELECT Directors.fullName as DirectorsName, STRING_AGG(nameMovie, ', ') as MoviesName
	FROM Movies INNER JOIN Directors ON Movies.idDirector = Directors.id
	GROUP BY Directors.fullName
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getDirectors
AS
BEGIN
	SELECT * FROM getDirectorsView
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE setFavMovie(
@Movie VARCHAR(32),
@idClient INTEGER
)
AS
DECLARE @idMovie INTEGER;
BEGIN
	SELECT @idMovie = Movies.id FROM Movies, Client
	WHERE (Movies.nameMovie = @Movie)
	UPDATE Client SET idFavoriteMovie = @idMovie
	WHERE (Client.id = @idClient)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE setFavActor(
@Actor VARCHAR(32),
@idClient INTEGER
)
AS
DECLARE @idActor INTEGER;
BEGIN
	SELECT @idActor = Actors.id FROM Actors, Client
	WHERE (Actors.fullName = @Actor)
	UPDATE Client SET idFavoriteActor = @idActor
	WHERE (Client.id = @idClient)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE setFavDirector(
@Director VARCHAR(32),
@idClient INTEGER
)
AS
DECLARE @idDirector INTEGER;
BEGIN
	SELECT @idDirector = Directors.id FROM Directors, Client
	WHERE (Directors.fullName = @Director)
	UPDATE Client SET idFavoriteDirector = @idDirector
	WHERE (Client.id = @idClient)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE setRating(
@Movie VARCHAR(32),
@myId INTEGER,
@myRating INTEGER
)
AS
DECLARE @idMovie INTEGER;
DECLARE @existsClient INTEGER;
BEGIN
	SELECT @idMovie = Movies.id FROM Movies
	WHERE (nameMovie = @Movie)

	SELECT @existsClient = COUNT(id) FROM ClientRatings 
	WHERE (idClient = @myId) AND (idMovie = @idMovie)
	if(@existsClient = 0)
	BEGIN
	INSERT INTO ClientRatings(rating, idClient, idMovie)
	VALUES(@myRating, @myId, @idMovie)
	END;
	ELSE
	BEGIN
		UPDATE ClientRatings SET rating = @myRating
		WHERE (idClient = @myId) AND (idMovie = @idMovie)
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getRating(
@myId INTEGER
)
AS
DECLARE @idMovie INTEGER;
BEGIN
	SELECT DISTINCT nameMovie, ClientRatings.rating, averageRating FROM Client, 
	Movies INNER JOIN ClientRatings ON ClientRatings.idMovie = Movies.id
	WHERE (@myId = ClientRatings.idClient) 
	ORDER BY averageRating DESC
END;
GO

USE courseWork;
GO
CREATE OR ALTER TRIGGER averageRating
ON ClientRatings
AFTER INSERT
AS
DECLARE @average INTEGER;
DECLARE @idMovie INTEGER;
	SELECT @average = SUM(ClientRatings.rating) / COUNT(ClientRatings.rating), @idMovie = ClientRatings.idMovie 
	FROM ClientRatings, INSERTED
	WHERE (ClientRatings.idMovie = INSERTED.idMovie)
	GROUP BY ClientRatings.idMovie
	UPDATE Movies SET  Movies.averageRating = @average
	WHERE @idMovie = Movies.id
GO

USE courseWork;
GO
CREATE OR ALTER TRIGGER averageRatingUpdate
ON ClientRatings
AFTER UPDATE
AS
DECLARE @average INTEGER;
DECLARE @idMovie INTEGER;
	SELECT @average = SUM(ClientRatings.rating) / COUNT(ClientRatings.rating), @idMovie = ClientRatings.idMovie 
	FROM ClientRatings, INSERTED
	WHERE (ClientRatings.idMovie = INSERTED.idMovie)
	GROUP BY ClientRatings.idMovie
	UPDATE Movies SET  Movies.averageRating = @average
	WHERE @idMovie = Movies.id
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE getDirectorsAdmin
AS
BEGIN
	SELECT fullName as ИмяРежиссера FROM Directors
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE createMovieRecord(
@filmName VARCHAR(32),
@directorName VARCHAR(32)
)
AS
DECLARE @existsMovie INTEGER
DECLARE @idDirector INTEGER
DECLARE @idMovie INTEGER
BEGIN
	SELECT @existsMovie = COUNT(id) FROM Movies WHERE nameMovie = @filmName;
	IF (@existsMovie > 0)
	BEGIN
		RAISERROR ('Такой фильм уже существует', 16, 1);
	END;
	else
	BEGIN
		INSERT INTO Movies(nameMovie)
		VALUES (@filmName)
	END;

	SELECT @idMovie = id FROM Movies
	WHERE nameMovie = @filmName

	SELECT @idDirector = id FROM Directors WHERE fullName = @directorName;
	IF (COUNT(@idDirector) != 1)
	BEGIN
		INSERT INTO Directors(fullName)
		VALUES (@directorName)
		
		SELECT @idDirector = id FROM Directors 
		WHERE fullName = @directorName
		
		UPDATE Movies SET idDirector = @idDirector
		WHERE id = @idMovie
	END;
	ELSE
	BEGIN
		UPDATE Movies SET idDirector = @idDirector
		WHERE id = @idMovie
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE createActorsRecord(
@MovieName VARCHAR(32),
@actorName VARCHAR(32)
)
AS
DECLARE @idActor INTEGER
DECLARE @idMovie INTEGER
BEGIN
	SELECT @idActor = id FROM Actors WHERE fullName = @actorName;
	IF (COUNT(@idActor) != 1)
	BEGIN
		INSERT INTO Actors(fullName)
		VALUES (@actorName)

		SELECT @idActor = id FROM Actors WHERE fullName = @actorName
		SELECT @idMovie = id FROM Movies WHERE nameMovie = @MovieName
		INSERT INTO ActorsMovies(idMovie, idActor)
		VALUES(@idMovie, @idActor)
	END;
	ELSE
	BEGIN
		SELECT @idMovie = id FROM Movies WHERE nameMovie = @MovieName
		INSERT INTO ActorsMovies(idMovie, idActor)
		VALUES(@idMovie, @idActor)
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE addActor(
@actorName VARCHAR(32)
)
AS
DECLARE @idActor INTEGER
BEGIN
	SELECT @idActor = id FROM Actors WHERE fullName = @actorName;
	IF (COUNT(@idActor) != 1)
	BEGIN
		INSERT INTO Actors(fullName)
		VALUES (@actorName)
	END;
	ELSE
	BEGIN
		RAISERROR ('Такой актер уже существует', 16, 1);
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE addDirector(
@directorName VARCHAR(32)
)
AS
DECLARE @idDirector INTEGER
BEGIN
	SELECT @idDirector = id FROM Directors WHERE fullName = @directorName;
	IF (COUNT(@idDirector) != 1)
	BEGIN
		INSERT INTO Directors(fullName)
		VALUES (@directorName)
	END;
	ELSE
	BEGIN
		RAISERROR ('Такой актер уже существует', 16, 1);
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE deleteMovie(
@movieName VARCHAR(32)
)
AS
DECLARE @idMovie INTEGER
BEGIN
	SELECT @idMovie = id FROM Movies
	WHERE @movieName = nameMovie
	UPDATE Client SET idFavoriteMovie = NULL
	WHERE @idMovie = idFavoriteMovie
	DELETE FROM Movies
	WHERE nameMovie = @movieName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE deleteActorsMovie(
@movieName VARCHAR(32),
@actorName VARCHAR(32)
)
AS
DECLARE @idMovie INTEGER
DECLARE @idActor INTEGER
BEGIN
	SELECT @idMovie = id FROM Movies
	WHERE @movieName = nameMovie
	SELECT @idActor = id FROM Actors
	WHERE @actorName = fullName
	DELETE FROM ActorsMovies
	WHERE (@idMovie = idMovie) AND (@idActor = idActor)
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE deleteDirector(
@directorName VARCHAR(32)
)
AS
DECLARE @idDirector INTEGER
BEGIN
	SELECT @idDirector = id FROM Directors
	WHERE @directorName = fullName
	UPDATE Client SET idFavoriteDirector = NULL
	WHERE @idDirector = idFavoriteDirector
	UPDATE Movies SET idDirector = NULL
	WHERE @idDirector = idDirector
	DELETE FROM Directors
	WHERE @directorName = fullName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE deleteActor(
@actorName VARCHAR(32)
)
AS
DECLARE @idActor INTEGER
BEGIN
	SELECT @idActor = id FROM Actors
	WHERE @actorName = fullName
	UPDATE Client SET idFavoriteActor = NULL
	WHERE @idActor = idFavoriteActor
	DELETE FROM Actors
	WHERE @actorName = fullName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE editDirector(
@directorOldName VARCHAR(32),
@directorNewName VARCHAR(32)
)
AS
BEGIN
	UPDATE Directors SET fullName = @directorNewName
	WHERE fullName = @directorOldName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE editActor(
@actorOldName VARCHAR(32),
@actorNewName VARCHAR(32)
)
AS
BEGIN
	UPDATE Actors SET fullName = @actorNewName
	WHERE fullName = @actorOldName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE editMovie(
@movieOldName VARCHAR(32),
@movieNewName VARCHAR(32)
)
AS
BEGIN
	UPDATE Movies SET nameMovie = @movieNewName
	WHERE nameMovie = @movieOldName
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE editMovieDirector(
@directorNewName VARCHAR(32),
@movieName VARCHAR(32)
)
AS
DECLARE @idDirector INTEGER
BEGIN
	SELECT @idDirector = id FROM Directors
	WHERE fullName = @directorNewName
	IF (COUNT(@idDirector) != 1)
	BEGIN
		INSERT INTO Directors(fullName)
		VALUES (@directorNewName)

		SELECT @idDirector = id FROM Directors
		WHERE fullName = @directorNewName

		UPDATE Movies SET idDirector = @idDirector
		WHERE nameMovie = @movieName
	END;
	ELSE
	BEGIN
		UPDATE Movies SET idDirector = @idDirector
		WHERE nameMovie = @movieName
	END;
END;
GO

USE courseWork;
GO
CREATE OR ALTER PROCEDURE editMovieActors(
@actorNewName VARCHAR(32),
@actorOldName VARCHAR(32),
@movieName VARCHAR(32)
)
AS
DECLARE @idActor INTEGER
DECLARE @idMovie INTEGER
BEGIN
	SELECT @idActor = id FROM Actors WHERE fullName = @actorNewName;
	IF (COUNT(@idActor) != 1)
	BEGIN
		INSERT INTO Actors(fullName)
		VALUES (@actorNewName)

		SELECT @idActor = id FROM Actors WHERE fullName = @actorNewName
		SELECT @idMovie = id FROM Movies WHERE nameMovie = @movieName
		INSERT INTO ActorsMovies(idMovie, idActor)
		VALUES(@idMovie, @idActor)
	END;
	ELSE
	BEGIN
		SELECT @idMovie = id FROM Movies WHERE nameMovie = @MovieName
		INSERT INTO ActorsMovies(idMovie, idActor)
		VALUES(@idMovie, @idActor)
	END;
END;
GO