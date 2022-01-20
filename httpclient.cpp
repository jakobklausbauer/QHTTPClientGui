#include "httpclient.h"
#include "ui_httpclient.h"
#include <QDebug>

HTTPClient::HTTPClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HTTPClient)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket();

    connect(m_socket, &QTcpSocket::connected, this, &HTTPClient::tcp_connect);
    connect(m_socket, &QTcpSocket::readyRead, this, &HTTPClient::tcp_receive);
}

void HTTPClient::on_g_absenden_clicked()
{
    ui->g_output->clear();

    m_hostname = ui->g_address->text();
    m_socket->connectToHost(m_hostname, m_port);
    if(!m_socket->waitForConnected(5000))
    {
        ui->g_output->setTextColor(QColor::fromRgb(255, 0, 0));
        ui->g_output->setText("Connection timed out!");
        ui->g_output->setTextColor(QColor::fromRgb(0, 0, 0));
        m_socket->disconnectFromHost();
    }
}

void HTTPClient::tcp_connect()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n").toLocal8Bit());
}

void HTTPClient::tcp_receive()
{
    ui->g_output->setText(m_socket->readAll());
    m_socket->disconnectFromHost();
}

HTTPClient::~HTTPClient()
{
    delete ui;
}
