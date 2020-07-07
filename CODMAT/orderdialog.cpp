#include "orderdialog.h"

orderdialog::orderdialog(QString g_text,QWidget *parent) : QDialog(parent)
{

ask_order =new QLineEdit();
    ask_order->setPlaceholderText(g_text);
    Button* done_button=createButton("Done",SLOT(end_order()));
     QGridLayout *mainLayout = new QGridLayout;
     mainLayout->addWidget(ask_order,0,0);
     mainLayout->addWidget(done_button,1,0);
     setLayout(mainLayout);
     setWindowTitle(" ");
}

Button* orderdialog::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }
void orderdialog::end_order()
{
    order=ask_order->text().toUInt();
    this->done(0);
}
