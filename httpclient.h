#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QMainWindow>
#include <QAbstractSocket>
#include <QTcpSocket>

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

    void tcp_connect();
    void tcp_receive();

private:
    QTcpSocket* m_socket = nullptr;
    const unsigned short m_port = 80;
    QString m_hostname;

    Ui::HTTPClient *ui;
};
#endif // HTTPCLIENT_H
