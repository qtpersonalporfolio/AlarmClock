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

protected:
    void mouseReleaseEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // ALARMCLOCKMAIN_H
