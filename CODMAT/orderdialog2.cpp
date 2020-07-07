#include "orderdialog2.h"

orderdialog2::orderdialog2(QWidget *parent) : QDialog(parent)
{

ask_row =new QLineEdit();
ask_col =new QLineEdit();
    ask_row->setPlaceholderText("Enter Number of Rows");
    ask_col->setPlaceholderText("Enter Number of Columns");
    Button* done_button=createButton("Done",SLOT(end_order()));
     QGridLayout *mainLayout = new QGridLayout;
     mainLayout->addWidget(ask_row,0,0);
     mainLayout->addWidget(ask_col,1,0);
     mainLayout->addWidget(done_button,2,0);
     setLayout(mainLayout);
     setWindowTitle(" ");
}

Button* orderdialog2::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }
void orderdialog2::end_order()
{
    row=ask_row->text().toUInt();
    col=ask_col->text().toUInt();
    this->done(0);
}
