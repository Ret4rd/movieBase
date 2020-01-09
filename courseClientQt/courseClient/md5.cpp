#include "md5.h"
#include <QCryptographicHash>

QString md5::getMd5(QString source)
{
    //source = "PASSWORD";
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(source.toUtf8());
    return md5.result().toHex().constData(); //В переменной cod полученный md5-хэш
}
