#include "httpclient.h"
#include "ui_httpclient.h"

HTTPClient::HTTPClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HTTPClient)
{
    ui->setupUi(this);
}

HTTPClient::~HTTPClient()
{
    delete ui;
}


void HTTPClient::on_g_absenden_clicked()
{

}
