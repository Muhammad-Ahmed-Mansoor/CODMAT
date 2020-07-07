#include "ouputopener.h"
#include<fstream>
#include<iostream>
#include<QFile>
using namespace std;
OuputOpener::OuputOpener(string path,QWidget *parent) : QWidget(parent)
{
ifstream file(path);
display=new QTextEdit();
string line;
while (!file.eof() )
   {
         getline(file,line);

         display->append(QString::fromStdString(line));

   }






display->setReadOnly(true);
QGridLayout *mainLayout = new QGridLayout;
   mainLayout->addWidget(display,0,0);
   setLayout(mainLayout);
}
