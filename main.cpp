#include "widget.h"
#include "encryotwidget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile f("./qss/skin.qss");
    f.open(QFile::ReadOnly);
    if(!f.isOpen()){
        qDebug("file not open");
    }
    qApp->setStyleSheet(f.readAll());
    qApp->setWindowIcon(QIcon(":/img/icon.ico"));
    f.close();
    EncryotWidget c;
    qDebug()<< QCoreApplication::applicationDirPath();
    c.show();


    return a.exec();
}
