#include "alarmclockmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wid;
    AlarmClockMain w(&wid);
    w.show();

    return a.exec();
}
