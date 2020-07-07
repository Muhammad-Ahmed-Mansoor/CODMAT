#ifndef CMPLX_H
#define CMPLX_H

//including libraries
#include<cmath>
#include<string>
#include<iostream>
#define PI 3.14159265
using namespace std;

//defining class Cmplx
class Cmplx
{
private://private access modifier
    double real, img, mod, phase;					//data members: real, imaginary, modulus and phase angle of complex numbers

    void calcPolar();								//sets the polar value implicitly when rect value is set

    void calcRect();								//sets the rect value implicitly when polar value is set

    char sign(double) const;						// returns the sign + or - of a given number



public://public access modifier
    Cmplx(double given_re = 1, double given_im = 0);//default constructor

    void setRect(double, double);					//mutator function for seting rectangular form

    void setRect();									//mutator function for seting rectangular form from keyboard

    void setPolar(double, double);				//mutator function for seting polar form

    void setPolar();								//mutator function for seting polar form from keyboard

    Cmplx& operator = (const Cmplx &given_num); //overloaded operator

    Cmplx& operator = (double given_num);       //overloaded operator

    bool operator ==(const Cmplx &given_num);  //overloaded operator

    bool operator !=(const Cmplx &given_num);  //overloaded operator

    double getReal() const;							//accessor for real

    double getImg() const;							//accessor for imaginary part

    double getMod() const;							//accessor for modulus

    double getPhase() const;						//accessor for phase angle

    Cmplx getConjugate() const;						//returns conjugate of the Cmplx object through which it is called

    void printRect() const;							//prints rectangular form of the Cmplx number

    void printPolar() const;						//prints polar form of the Cmplx number

    string str_rect() const;                        //prints rectangular form with correct notation

    string str_polar() const;                      //prints polar form with correct notation


    ~Cmplx();										//destructor

};//end class Cmplx



Cmplx operator + (const Cmplx& a, const Cmplx& b);							//adds two Cmplx numbers

Cmplx operator - (const Cmplx& a, const Cmplx& b);				//subtracts two Cmplx numbers

Cmplx operator * (const Cmplx& a, const Cmplx& b);						//multiplies two Cmplx numbers

Cmplx operator / (const Cmplx& a, const Cmplx& b);					//divides two Cmplx numbers

Cmplx operator ^ (const Cmplx& x, int n);							//raises a Cmplx number to an integar power


#endif
