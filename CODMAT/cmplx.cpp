
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include"Cmplx.h"
using namespace std;

//sets the polar value implicitly when rect value is set
void Cmplx::calcPolar()
{

    //calculating modulus (magnitude)
    mod = sqrt(real*real + img*img);

    //determining phase with correct quadrant
    if (real != 0)
    {
        phase = atan(abs(img / real)) * 180 / PI;

        //for quadrant
        if (real < 0 && img >= 0)
            phase = 180 - phase;
        else if (real < 0 && img < 0)
            phase -= 180;
        else if (real > 0 && img < 0)
            phase *= -1;
    }
    //for zero cmplx number
    else if (img == 0)
        phase = 0;

    //for positive pure imaginary number
    else if (img>0)
        phase = 90;

    //for negative pure imaginary number
    else
        phase = -90;


    /*Due to the natural inaccuracy of doubles, sometimes zero is written as a
    very small number like 1e-15. This gets rid of that inaccuracy by treating
    any value less than 0.0001 as zero*/
    if (mod < 0.0001)
        mod = 0;
    if (abs(phase) < 0.0001)
        phase = 0;


}//end function


//sets the rect value implicitly when polar value is set
void Cmplx::calcRect()
{
    real = mod*cos(phase*PI / 180);
    img = mod*sin(phase*PI / 180);

    /*Due to the natural inaccuracy of doubles, sometimes zero is written as a
    very small number like 1e-15. This gets rid of that inaccuracy by treating
    any value less than 0.0001 as zero*/
    if (abs(real) < 0.0001)
        real = 0;

    if (abs(img) < 0.0001)
        img = 0;
}//end function

// returns the sign + or - of a given number
char Cmplx::sign(double num) const
{
    if (num >= 0)
        return '+';
    else
        return'-';
}//end function

//default constructor
Cmplx::Cmplx(double given_re, double given_im)
{
    setRect(given_re, given_im);
}//end function


//mutator function for setting rectangular form
void Cmplx::setRect(double given_re, double given_im)
{
    real = given_re;
    img = given_im;
    /*Due to the natural inaccuracy of doubles, sometimes zero is written as a
    very small number like 1e-15. This gets rid of that inaccuracy by treating
    any value less than 0.00001 as zero*/
    if (abs(real) < 0.00001)
        real = 0;

    if (abs(img) < 0.00001)
        img = 0;
    calcPolar();


}//end function

//mutator function for setting rectangular form from keyboard
void Cmplx::setRect()
{
    double given_re, given_im;

    cout << "\n>>  ";
    cin >> given_re;
    cout << " +j(";
    cin >> given_im;

    real = given_re;
    img = given_im;



    calcPolar();

}//end function

//mutator function for setting polar form
void Cmplx::setPolar(double given_mod, double given_phase)
{
    if (given_mod < 0)
    {
        given_mod = -given_mod;
        given_phase += 180;
    }

    mod = given_mod;

    while (given_phase > 180)
    {
        given_phase -= 360;
    }

    while (given_phase < -180)
    {
        given_phase += 360;
    }
    phase = given_phase;

    calcRect();

}//end function

//mutator function for setting polar form from keyboard
void Cmplx::setPolar()
{
    double given_mod, given_phase;

    cout << "\n>>  ";
    cin >> given_mod;
    cout << "<";
    cin >> given_phase;

    if (given_mod < 0)
    {
        given_mod = -given_mod;
        given_phase += 180;
    }

    mod = given_mod;

    while (given_phase > 180)
    {
        given_phase -= 360;
    }

    while (given_phase < -180)
    {
        given_phase += 360;
    }
    phase = given_phase;

    calcRect();

}//end function



Cmplx&  Cmplx::operator = (const Cmplx& given_num)
{
    setRect(given_num.real, given_num.img);
    return *this;
}


Cmplx& Cmplx::operator = (double given_num)
{
    setRect(given_num, 0);
    return *this;
}

bool Cmplx::operator ==(const Cmplx &given_num)
{
    return ((given_num.real == real) && (given_num.img == img));
}

bool Cmplx::operator !=(const Cmplx &given_num)
{
    return !((given_num.real == real) && (given_num.img == img));
}


//accessor for real
double Cmplx::getReal() const
{
    return real;
}//end function

//accessor for imaginary part
double Cmplx::getImg() const
{
    return img;
}//end function

//accessor for modulus
double Cmplx::getMod() const
{
    return mod;
}//end function

//accessor for phase angle
double Cmplx::getPhase() const
{
    return phase;
}//end function

//returns conjugate of the Cmplx object through which it is called
Cmplx Cmplx::getConjugate() const
{
    return Cmplx(real, -img);
}//end function

//prints rectangular form of the Cmplx number
void Cmplx::printRect() const
{
    if (img == 0)
        cout << real;
    else if (real == 0)
        cout << sign(img) << "j" << fabs(img);
    else
        cout  << real << sign(img) << "j" << fabs(img);
}//end function

//prints polar form of the Cmplx number
void Cmplx::printPolar() const
{
    cout << mod << "<"<< phase << "*";
}//end function
//prints rectangular form with correct notation
string Cmplx::str_rect() const
{
    ostringstream oss;


    if (img == 0)
        oss << real;
    else if (real == 0&&img<0)
        oss << sign(img) << "j" << fabs(img);
    else if (real == 0 && img>0)
        oss  << "j" << fabs(img);
    else
        oss << real << sign(img) << "j" << fabs(img);

    return oss.str();
}
//prints polar form with correct notation
string Cmplx::str_polar() const
{
    ostringstream oss;


    oss << mod << "<" << phase << "*";

    return oss.str();
}

//destructor
Cmplx::~Cmplx()
{
    //empty destructor
}//end function

//THE FOLLOWING ARE NOT PART OF CMPLX CLASS BUT HAVE BEEN DECLARED IN THE CMPLX HEADER FILE
//adds two Cmplx numbers
Cmplx operator + (const Cmplx& a, const Cmplx& b)
{
    Cmplx add;

    add.setRect(a.getReal() + b.getReal(), a.getImg() + b.getImg());

    return add;

}//end function

//subtracts two Cmplx numbers
Cmplx operator - (const Cmplx& a, const Cmplx& b)
{
    Cmplx sub;

    sub.setRect(a.getReal() - b.getReal(), a.getImg() - b.getImg());

    return sub;

}//end function

//multiplies two Cmplx numbers
Cmplx operator * (const Cmplx& a, const Cmplx& b)
{
    Cmplx mul;

    mul.setPolar(a.getMod() *b.getMod(), a.getPhase() + b.getPhase());

    return mul;

}//end function

//divides two Cmplx numbers
Cmplx operator / (const Cmplx& a, const Cmplx& b)
{
    Cmplx div;

    div.setPolar(a.getMod() / b.getMod(), a.getPhase() - b.getPhase());

    return div;

}//end function

//raises a Cmplx number to an integar power
Cmplx operator ^ (const Cmplx& x, int n)
{
    Cmplx p;

    p.setPolar(pow(x.getMod(), n), x.getPhase()*n);

    return p;


}//end function
