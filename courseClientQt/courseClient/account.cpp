#include "account.h"

Account::Account()
{
    this->id = "";
}

Account::Account(QString id, QString firstName, QString secondName, QString loginClient, QString passwordClient,
                 QString favMovie, QString favDirector, QString favActor)
{
    this->id = id;
    this->firstName = firstName;
    this->secondName = secondName;
    this->loginClient = loginClient;
    this->passwordClient = passwordClient;
    this->favMovie = favMovie;
    this->favDirector = favDirector;
    this->favActor = favActor;
}
