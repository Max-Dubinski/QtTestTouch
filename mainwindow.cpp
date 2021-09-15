#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->pushButton_2->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    QPushButton* btn = qobject_cast<QPushButton*>(obj);
    if (ev->type() == QEvent::Type::MouseButtonPress)
    {
        ui->textEdit->append("MouseButtonPress");

        btn->setDown(true);
        return true;
    }
    if (ev->type() == QEvent::Type::MouseButtonRelease)
    {
        ui->textEdit->append("MouseButtonRelease");

        bool wasDown = btn->isDown();
        btn->setDown(false);
        if (wasDown)
            btn->click();
        return true;
    }
    if (ev->type() == QEvent::Type::TouchBegin)
    {
        ui->textEdit->append("TouchBegin");

        btn->setDown(true);
        //return true;
    }
    if (ev->type() == QEvent::Type::TouchCancel || ev->type() == QEvent::Type::TouchEnd)
    {
        ui->textEdit->append("TouchEnd");

        bool wasDown = btn->isDown();
        btn->setDown(false);
        if (wasDown)
            btn->click();
        return true;
    }
    return false;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->append("Button1 - clicked");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->append("Button2 - clicked");
}
