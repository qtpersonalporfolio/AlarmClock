#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

#include "alarmclockmain.h"
#include "ui_alarmclockmain.h"



AlarmClockMain::AlarmClockMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlarmClockMain)
{
    ui->setupUi(this);

    connect(this, &AlarmClockMain::customContextMenuRequested, this, &AlarmClockMain::showContextMenu);
    setAttribute(Qt::WA_TranslucentBackground);

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags());

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AlarmClockMain::UpdateTime);
    timer->start(1000);

    UpdateTime();
}

AlarmClockMain::~AlarmClockMain()
{
    delete ui;
}

void AlarmClockMain::UpdateTime()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeText = currentTime.toString("hh:mm");
    if(currentTime.second() % 2 == 0)
    {
        currentTimeText[2] = ' ';
    }
    ui->TimerDisplay->display(currentTimeText);
}

void AlarmClockMain::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu;
    contextMenu.addAction(QString("Exit"), this, SLOT(close()));
    contextMenu.exec(mapToGlobal(pos));
}

void AlarmClockMain::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        emit customContextMenuRequested(e->pos());
    }
    else
    {
        QMainWindow::mousePressEvent(e);
    }
}

void AlarmClockMain::mousePressEvent(QMouseEvent *e)
{
    m_mousePos = e->pos();
}

void AlarmClockMain::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPos() - m_mousePos);
}



















