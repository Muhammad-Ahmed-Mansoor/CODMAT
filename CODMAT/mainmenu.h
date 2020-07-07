#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "button.h"
#include<QGridLayout>
#include"squarematrixinput.h"
#include<fstream>
#include"orderdialog.h"
#include"orderdialog2.h"
class MainMenu : public QWidget
{
    Q_OBJECT
private:
     Button *createButton(const QString &text, const char *member);

public:
    explicit MainMenu(QWidget *parent = nullptr);

private slots:
     void equations();
     void inverse();
     void ref();
     void rref();
     void transpose();
     void determinant();
     void add();
     void subtract();
     void multiply();
     void power();
};

#endif // MAINMENU_H
