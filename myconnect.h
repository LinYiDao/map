#ifndef MYCONNECT_H
#define MYCONNECT_H

#include <QJsonArray>
#include <QJsonObject>
#include <QObject>


class MyConnect : public QObject
{
    Q_OBJECT
public:
    explicit MyConnect(QObject *parent = nullptr);

signals:
    void sigSendMessageToJs(QJsonObject str);

public slots:
    void Test();
    void sendSig(QJsonObject str);
private:

};

#endif // MYCONNECT_H
