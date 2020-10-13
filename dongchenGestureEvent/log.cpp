#include "log.h"

//构造函数
Log::Log(QObject *parent) : QObject(parent)
{
    //
}


//视频反馈系统-日志记录
void Log::log(QString message)
{
    logMutes.lock();

    QDateTime time = QDateTime::currentDateTime();
    logpath = QString("D:/log/%1.txt").arg(time.toString("yyyyMMdd"));
    file.setFileName(logpath);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    if(!file.isOpen())
    {
       //
    }

    QTextStream stream(&file);
    QString logMessage;
    logMessage += dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    logMessage += ":";
    logMessage += message;
    logMessage += "\r\n";
    stream << logMessage<<endl;

    file.close();

    logMutes.unlock();

}
