#ifndef FH_COMPLEX_H
#define FH_COMPLEX_H
#define Pi acos(-1.0)
#define Divided_By_Zero_Num Complex(DBL_MAX, DBL_MAX)

#include <iostream>
#include <math.h>	// 只 在计算  实数指数次幂  和将 复数 与 其指数形式 互换时 使用
using namespace std;

struct Power_Form_Of_Complex
{
	double Rho_Squared;
	double Theta;
};

class Complex
{
private:
	double Real;
	double Imagination;

public:
	Complex(double R = 0, double I = 0):Real(R), Imagination(I){}

	Complex operator + (Complex &);
	Complex operator - (Complex &);
	Complex operator * (Complex &);
	Complex operator / (Complex &);
	Complex operator + (const double &);
	Complex operator - (const double &);
	Complex operator * (const double &);
	Complex operator / (const double &);
	Complex & operator ++ ();
	Complex operator ++ (int);
	Complex & operator -- ();
	Complex operator -- (int);
	friend Complex operator + (const double &, Complex &);
	friend Complex operator - (const double &, Complex &);
	friend Complex operator * (const double &, Complex &);
	friend Complex operator / (const double &, Complex &);
	bool operator == (Complex &);
	bool operator == (const double &);
	friend bool operator == (const double &, Complex &);
	friend ostream & operator << (ostream &, const Complex &);
	
	friend Complex Power(Complex & root, const double & times);
	friend Complex Power(Complex & root, const int & times);

	double Get_Real();
	double Get_Imagination();

	void Print();

	Power_Form_Of_Complex To_Power_Form();
	friend Complex To_Normal_Form(Power_Form_Of_Complex &);
};

#endif // !FH_COMPLEX_H
