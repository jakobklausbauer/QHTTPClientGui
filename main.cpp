#include "httpclient.h"

#include <QApplication>

/*
    - Eingabefeld für URL/Adresse
    - OK-Button zum Bestätigen
    - Ausgabefeld für HTTP-Response
*/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTTPClient w;
    w.show();
    return a.exec();
}
