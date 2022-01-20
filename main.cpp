#include "httpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTTPClient w;
    w.show();
    return a.exec();
}
