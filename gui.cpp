#include "gui.h"
#include <QDebug>
#include "httpclient.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Gui::on_goButton_clicked()
{
    HttpClient* Client = new HttpClient(this);

    bool status = Client->Connect80(hostEntry->text());

    if(status)
    {
        resultBrowser->append("Connected");
        resultBrowser->append(Client->Text);

    }
    else
    {
        resultBrowser->append("Connect Failed");
    }
}
