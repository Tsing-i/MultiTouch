#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGestureEvent>
#include <QDebug>
#include "log.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Log log;

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void dealMultiTouch(QPointF p1, QPointF p2, QPointF p3, QPointF p4);

};

#endif // MAINWINDOW_H
