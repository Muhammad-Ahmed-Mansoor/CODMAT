#include "mainmenu.h"
#include<iostream>
#include"ouputopener.h"
#include"equationinput.h"
#include<QDesktopServices>
#include"matrix.h"
#include"rectmatrixinput.h"
using namespace std;

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
Button* equation_button=createButton("Simultaneous Equations",SLOT(equations()));
Button* determinant_button=createButton("Determinants",SLOT(determinant()));
Button* inverse_button=createButton("Inverse",SLOT(inverse()));
Button* ref_button=createButton("Row Echelon Form",SLOT(ref()));
Button* rref_button=createButton("Reduced Row Echelon Form",SLOT(rref()));
Button* transpose_button=createButton("Transpose",SLOT(transpose()));
Button* add_button=createButton("+",SLOT(add()));
Button* subtract_button=createButton("-",SLOT(subtract()));
Button* multiply_button=createButton("x",SLOT(multiply()));
Button* power_button=createButton("^",SLOT(power()));

QGridLayout *mainLayout = new QGridLayout;
mainLayout->setSizeConstraint(QLayout::SetFixedSize);

mainLayout->addWidget(equation_button,0,0,1,2);
mainLayout->addWidget(determinant_button,1,0,1,2);
mainLayout->addWidget(inverse_button,2,0,1,2);
mainLayout->addWidget(ref_button,3,0,1,2);
mainLayout->addWidget(rref_button,4,0,1,2);
mainLayout->addWidget(transpose_button,5,0,1,2);
mainLayout->addWidget(add_button,6,0);
mainLayout->addWidget(subtract_button,6,1);
mainLayout->addWidget(multiply_button,7,0);
mainLayout->addWidget(power_button,7,1);

setLayout(mainLayout);

 setWindowTitle("CODMAT");
}

Button *MainMenu::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
    // button->setFlat(true);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }

void MainMenu::equations()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog* get_order=new orderdialog("Enter the number of variables.");
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
EquationInput* input=new EquationInput(get_order->order);
input->setModal(true);
input->show();
input->exec();
input->mat->solve_equations(*(input->vec),true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}

void MainMenu::determinant()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog* get_order=new orderdialog("Enter the order of matrix.");
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
SquareMatrixInput* input=new SquareMatrixInput(get_order->order);
input->setModal(true);
input->show();
input->exec();
input->mat->determinant(true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}
void MainMenu::ref()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();
input->mat->ref(true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}
void MainMenu::rref()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();
input->mat->rref(true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}
void MainMenu::inverse()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog* get_order=new orderdialog("Enter the order of matrix.");
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
SquareMatrixInput* input=new SquareMatrixInput(get_order->order);
input->setModal(true);
input->show();
input->exec();
input->mat->inverse(true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}
void MainMenu::transpose()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();
input->mat->transpose(true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;
}
void MainMenu::add()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();



RectMatrixInput* input2=new RectMatrixInput(get_order->row,get_order->col);
input2->setModal(true);
input2->show();
input2->exec();




input->mat->add(*(input2->mat),true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;


}
void MainMenu::subtract()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();



RectMatrixInput* input2=new RectMatrixInput(get_order->row,get_order->col);
input2->setModal(true);
input2->show();
input2->exec();




input->mat->subtract(*(input2->mat),true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;

}
void MainMenu::multiply()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog2* get_order=new orderdialog2();
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
RectMatrixInput* input=new RectMatrixInput(get_order->row,get_order->col);
input->setModal(true);
input->show();
input->exec();

orderdialog* get_order2=new orderdialog("Enter Columns For 2nd Matrix");
get_order2->setModal(true);
get_order2->show();
get_order2->exec();

RectMatrixInput* input2=new RectMatrixInput(get_order->col,get_order2->order);
input2->setModal(true);
input2->show();
input2->exec();




input->mat->multiply(*(input2->mat),true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;

}
void MainMenu::power()
{
    ofstream* out=new ofstream("OUTPUT.txt");
    orderdialog* get_order=new orderdialog("Enter the order of matrix.");
    get_order->setModal(true);
    get_order->show();
    get_order->exec();
SquareMatrixInput* input=new SquareMatrixInput(get_order->order);
input->setModal(true);
input->show();
input->exec();
orderdialog* exp=new orderdialog("Enter the exponent.");
exp->setModal(true);
exp->show();
exp->exec();

input->mat->int_pow(exp->order,true,*out);

QDesktopServices::openUrl(QUrl("OUTPUT.txt"));

delete get_order;
delete out;

}
