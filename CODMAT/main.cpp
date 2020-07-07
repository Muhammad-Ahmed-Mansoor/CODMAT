// including libraries
#include"cmplx.h"
#include"matrix.h"
#include"squarematrix.h"
#include"identitymatrix.h"
#include "rowvector.h"
#include "columnvector.h"
#include"augmentedmatrix.h"
#include"mainmenu.h"
#include<QApplication>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<QSplashScreen>
using namespace std;

int main(int argc, char **argv)
{


    QApplication app (argc, argv);
    QPixmap pixmap("splash.png");
        QSplashScreen splash(pixmap);
        splash.show();

     MainMenu window;
     window.show();

     return app.exec();


} // end main
