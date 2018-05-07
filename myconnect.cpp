 #include "myconnect.h"
#include<QDebug>
MyConnect::MyConnect(QObject *parent) : QObject(parent)
{
}
void MyConnect::Test()
{
    qDebug()<<"qq";
}

void MyConnect::sendSig(QJsonObject str)
{
    emit sigSendMessageToJs(str);

}


