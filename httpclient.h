#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HTTPClient; }
QT_END_NAMESPACE

class HTTPClient : public QMainWindow
{
    Q_OBJECT

public:
    HTTPClient(QWidget *parent = nullptr);
    ~HTTPClient();

private slots:
    void on_g_absenden_clicked();

private:
    Ui::HTTPClient *ui;
};
#endif // HTTPCLIENT_H
