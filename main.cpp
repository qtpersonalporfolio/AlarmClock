#include "alarmclockmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName(QString("Esteban Lopez"));
    a.setApplicationName(QString("Alarm Clock"));



    QWidget wid;
    AlarmClockMain w(&wid);
    w.show();

    return a.exec();
}
