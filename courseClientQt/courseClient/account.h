#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class Account
{
public:
    Account();
    Account(QString id, QString firstName, QString secondName, QString loginClient, QString passwordClient,
            QString favMovie, QString favDirector, QString favActor);
    QString id;
    QString firstName;
    QString secondName;
    QString loginClient;
    QString passwordClient;
    QString favMovie;
    QString favDirector;
    QString favActor;

};

#endif // ACCOUNT_H
