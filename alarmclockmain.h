#ifndef ALARMCLOCKMAIN_H
#define ALARMCLOCKMAIN_H

#include <QMainWindow>

namespace Ui {
class AlarmClockMain;
}

class AlarmClockMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlarmClockMain(QWidget *parent = nullptr);
    ~AlarmClockMain();

private:
    Ui::AlarmClockMain *ui;
    QPoint m_mousePos;

private slots:
    void UpdateTime();
    void showContextMenu(const QPoint &pos);
    void TriggerAlarm();

protected:
    void mouseReleaseEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);
};

#endif // ALARMCLOCKMAIN_H
