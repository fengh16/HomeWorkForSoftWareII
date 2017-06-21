#include "FH_Complex.h"

Power_Form_Of_Complex Complex::To_Power_Form()
{
	Power_Form_Of_Complex Ans;
	Complex temp(*this);
	Ans.Rho_Squared = temp.Imagination * temp.Imagination + temp.Real * temp.Real;
	if (Real == 0)
	{
		if (Imagination == 0)
		{
			Ans.Theta = 0;
			return Ans;
		}
		else if (Imagination > 0)
		{
			Ans.Theta = Pi / 2;
			return Ans;
		}
		else
		{
			Ans.Theta = -Pi / 2;
			return Ans;
		}
	}
	else if (Imagination == 0)
	{
		if (Real > 0)
		{
			Ans.Theta = 0;
			return Ans;
		}
		else
		{
			Ans.Theta = Pi;
			return Ans;
		}
	}
	Ans.Theta = asin(temp.Real / (sqrt(Ans.Rho_Squared)));
	if (Imagination < 0)
		Ans.Theta = -Ans.Theta;
	return Ans;
}

Complex To_Normal_Form(Power_Form_Of_Complex & temp)
{
	double Len = sqrt(temp.Rho_Squared);
	return Complex(Len * cos(temp.Theta), Len * sin(temp.Theta));
}

Complex Complex::operator+(Complex & m)
{
	Complex ans(Real + m.Real, Imagination + m.Imagination);
	return ans;
}

Complex Complex::operator-(Complex & m)
{
	Complex ans(Real - m.Real, Imagination - m.Imagination);
	return ans;
}

Complex Complex::operator*(Complex & m)
{
	Complex ans(Real * m.Real - Imagination * m.Imagination, Real * m.Imagination + Imagination * m.Real);
	return ans;
}

Complex Complex::operator/(Complex & m)
{
	double Lower = m.Real * m.Real + m.Imagination * m.Imagination;
	if (Lower == 0)
		return Divided_By_Zero_Num;
	Complex ans((Real * m.Real + Imagination * m.Imagination) / Lower, (-Real * m.Imagination + Imagination * m.Real) / Lower);
	return ans;
}

Complex Complex::operator+(const double & m)
{
	Complex ans(Real + m, Imagination);
	return ans;
}

Complex Complex::operator-(const double & m)
{
	Complex ans(Real - m, Imagination);
	return ans;
}

Complex Complex::operator*(const double & m)
{
	Complex ans(Real * m, Imagination * m);
	return ans;
}

Complex Complex::operator/(const double & m)
{
	if (m == 0)
		return Divided_By_Zero_Num;
	Complex ans(Real / m, Imagination / m);
	return ans;
}

Complex & Complex::operator++()
{
	Real++;
	Imagination++;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex ans(*this);
	Real++;
	Imagination++;
	return ans;
}

Complex & Complex::operator--()
{
	Real--;
	Imagination--;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex ans(*this);
	Real--;
	Imagination--;
	return ans;
}

bool Complex::operator==(Complex & m)
{
	return Real - m.Real < 0.000001 && Real - m.Real > -0.000001 && Imagination - m.Imagination < 0.000001 && Imagination - m.Imagination > -0.000001;
}

bool Complex::operator==(const double & m)
{
	return Real - m < 0.000001 && Real - m > -0.000001 && Imagination < 0.000001 && Imagination > -0.000001;
}

Complex Power(Complex & root, const double & times)
{
	Power_Form_Of_Complex Temp = root.To_Power_Form();
	if (Temp.Rho_Squared == 0 && times <= 0)
		return Divided_By_Zero_Num;
	Temp.Rho_Squared = pow(Temp.Rho_Squared, times);
	Temp.Theta = Temp.Theta * times;
	return To_Normal_Form(Temp);
}

Complex Power(Complex & root, const int & times)
{
	Complex Ans(root);
	for (int i = 1; i < times; i++)
	{
		Ans = root * Ans;
	}
	for (int i = 0; i >= times; i--)
	{
		if (Ans.Real == 0 && Ans.Imagination == 0)
			return Divided_By_Zero_Num;
		Ans = Ans / root;
	}
	return Ans;
}

double Complex::Get_Real()
{
	return Real;
}

double Complex::Get_Imagination()
{
	return Imagination;
}

void Complex::Print()
{
	Complex Num(*this);
	if (Num == Num.Get_Real())
		cout << Num.Real;
	else if (Num.Real < 0.000001 && Num.Real > -0.000001)
	{
		if (Num.Imagination < 0)
			cout << "- " << -Num.Imagination << "i";
		else
			cout << Num.Imagination << "i";
	}
	else
	{
		if (Num.Imagination < 0)
			cout << Num.Real << " - " << -Num.Imagination << "i";
		else
			cout << Num.Real << " + " << Num.Imagination << "i";
	}
}

Complex operator + (const double & a, Complex & b)
{
	return b + a;
}

Complex operator - (const double & a, Complex & b)
{
	Complex c(a, 0);
	return c - b;
}

Complex operator * (const double & a, Complex & b)
{
	return b * a;
}

Complex operator / (const double & a, Complex & b)
{
	Complex c(a, 0);
	return c / b;
}

bool operator==(const double & a, Complex & b)
{
	return b == a;
}

ostream & operator << (ostream & out, const Complex & Num)
{
	if (Num.Imagination < 0.000001 && Num.Imagination > -0.000001)
		out << Num.Real;
	else if (Num.Real < 0.000001 && Num.Real > -0.000001)
	{
		if (Num.Imagination < 0)
			out << "- " << -Num.Imagination << "i";
		else
			out << Num.Imagination << "i";
	}
	else
	{
		if (Num.Imagination < 0)
			out << Num.Real << " - " << -Num.Imagination << "i";
		else
			out << Num.Real << " + " << Num.Imagination << "i";
	}
	return out;
}

