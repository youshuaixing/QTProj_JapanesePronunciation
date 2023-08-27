#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowFlags(window.windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    window.show();
    return a.exec();
}
