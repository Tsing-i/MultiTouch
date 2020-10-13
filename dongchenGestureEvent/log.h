#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <qmutex.h>

class Log : public QObject
{
    Q_OBJECT

public:
    explicit Log(QObject *parent = 0);
    void log(QString message);

signals:

public slots:

private:
    QFile file;
    QDateTime dateTime;
    QMutex logMutes;
    QString logpath;
};
