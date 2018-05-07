#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QWebEngineView>
#include<QJsonObject>
#include <QJsonArray>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void send();
    void updateObj();
signals:
    void sigSendMessageToJs(QJsonObject str);


private:
    QPushButton *mpQtSendBtnByInteractObj;
    Ui::Dialog *ui;
    QWebEngineView *view;
    QJsonObject obj;
    int count;
    QJsonArray array;

};

#endif // DIALOG_H
