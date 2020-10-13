#include "mainwindow.h"
#include "ui_mainwindow.h"


//https://blog.csdn.net/qq_41949352/article/details/94460450
//https://blog.csdn.net/luoyayun361/article/details/54426356
//https://blog.csdn.net/luoyayun361/article/details/54409203



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置监听标识
    this->setAttribute(Qt::WA_AcceptTouchEvents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dealMultiTouch(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
    if (p1 == p2 || p3 == p4)
    {
        log.log("Now equal!");
    }
    else
    {
        double delta1 = QLineF(p1, p2).length();
        double delta2 = QLineF(p3, p4).length();
        double delta = delta1;

        if (delta1 < delta2)
        {
            delta = delta1;

        }
        else
        {
            delta = delta2;
        }

        double x1 = p2.x() - p1.x();
        double y1 = p2.y() - p1.y();
        double x2 = p4.x() - p3.x();
        double y2 = p4.y() - p3.y();
        double molecule = x1 * x2 + y1 * y2;
        double Denominator = sqrt((pow(x1, 2) + pow(y1, 2)) * (pow(x2, 2) + pow(y2, 2)));
        double cosA = molecule / Denominator;

        if (cosA < 0)
        {
            //通过向量算出两者之间的夹角的余弦值，因为范围是（0，180，所以大于90度，余弦值必定小于0

            double endL = QLineF(p2, p4).length();
            double startL = QLineF(p1, p3).length();

            //然后来判断是放大还是缩小操作算出两指起始点以及终止点之间的距离，如果起始点间的距离大于
            //终止点间的距离则是缩小，反正放大

            if (endL > startL)
            {
                log.log("zoom in !");
            }

            else
            {
                log.log("zoom out!");
            }
        }
    }
}


bool MainWindow::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {

        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();
        if (touchPoints.count() == 2)
        {
            QPointF p1 = touchPoints.at(0).startPos();
            QPointF p2 = touchPoints.at(0).lastPos();
            QPointF p3 = touchPoints.at(1).startPos();
            QPointF p4 = touchPoints.at(1).lastPos();

            dealMultiTouch(p1,p2,p3,p4);

        }
        else if(touchPoints.count() == 1)
        {
            QPointF p1 = touchPoints.at(0).startPos();
            QPointF p2 = touchPoints.at(0).lastPos();


            int dong1 =(int)p1.x();
            int dong2 =(int)p2.x();
            QString test ="one-" +QString::number(dong1)+"-"+QString::number(dong2);
            log.log(test);

        }
        return true;
    }
    default:
        break;
    }

    return QWidget::event(event);


}

