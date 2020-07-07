#ifndef OUPUTOPENER_H
#define OUPUTOPENER_H

#include <QWidget>
#include<QTextEdit>
#include<fstream>
#include<iostream>
#include<QGridLayout>
using namespace std;
class OuputOpener : public QWidget
{
    Q_OBJECT
private:
    QTextEdit *display;
public:
    explicit OuputOpener(string path,QWidget *parent = nullptr);

signals:

public slots:
};

#endif // OUPUTOPENER_H
