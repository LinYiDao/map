#include "dialog.h"
#include "myconnect.h"
#include "ui_dialog.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QWebChannel>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    count = 0;
    mpQtSendBtnByInteractObj = new QPushButton("Send", this);
    QHBoxLayout *pQtSendHLayout = new QHBoxLayout;
    pQtSendHLayout->setMargin(0);
    pQtSendHLayout->setSpacing(0);

    pQtSendHLayout->addSpacing(5);
    pQtSendHLayout->addWidget(mpQtSendBtnByInteractObj);
    ui->setupUi(this);
    view = new QWebEngineView(this);
    view->page()->load(QUrl("file:///G:/Qt/study/demo4/index.html"));
    QWebChannel *channel = new QWebChannel(this);
    //将myconnect作为交互类
    MyConnect *c = new MyConnect();
    channel->registerObject(QStringLiteral("coc"),c);
    view->page()->setWebChannel(channel);
    QVBoxLayout *pJSTotalVLayout = new QVBoxLayout();
    pJSTotalVLayout->setMargin(0);
    pJSTotalVLayout->setSpacing(0);
    pJSTotalVLayout->addWidget(view);


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(5);
    mainLayout->setSpacing(0);
    mainLayout->addLayout(pJSTotalVLayout);
    mainLayout->addSpacing(5);
    mainLayout->addLayout(pQtSendHLayout);
    setLayout(mainLayout);
    this->setMinimumSize(800, 600);

    QJsonObject obj1 ={
        {"lng",116.405289}, {"lat",39.904987}
    };
    QJsonObject obj2 ={
        {"lng",113.405289}, {"lat",40.504987}
    };
    QJsonObject obj3 ={
        {"lng",111.405289}, {"lat",41.104987}
    };
    array.push_back(obj1);
    array.push_back(obj2);
    array.push_back(obj3);

    connect(mpQtSendBtnByInteractObj, &QPushButton::clicked, this,&Dialog::send);
    connect(this,&Dialog::sigSendMessageToJs,c,&MyConnect::sendSig);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::send()
{
    /*var myPath = [
             [116.405289, 39.904987],
             [113.964458, 40.54664],
             [111.47836, 41.135964],
             [108.949297, 41.670904],
             [106.380111, 42.149509],
             [103.774185, 42.56996],
             [101.135432, 42.930601],
             [98.46826, 43.229964],
             [95.777529, 43.466798],
             [93.068486, 43.64009],
             [90.34669, 43.749086],
             [87.61792, 43.793308]
         ];
         */

    updateObj();


    while(true){
        if(!obj.isEmpty()){
            emit sigSendMessageToJs(obj);
            obj.remove("lng");
            obj.remove("lat");

            qDebug()<<obj;
            break;
        }
    }
}

void Dialog::updateObj()
{

    obj=array[count].toObject();
    array.pop_front();
}
