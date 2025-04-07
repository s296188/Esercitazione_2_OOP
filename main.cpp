#include <iostream>
#include <concepts>
#include "ComplexNumber.hpp"

using namespace std;


int main(void)
{
	using C = complex_number<double>;
	
	C z1(2.0,3.0);
	C z2(5.0,-4.8);
	
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	
	C z5 = z1.conjugate();
	cout << "congiugato di z1 = " << z5 << endl;
	
	z2 += z1;
	
	cout << "z1 + z2 = " << z2 << endl;
	
	C z3 = z1 + z2;
	
	cout << "z3 = " << z3 << endl;
	
	z2 *= z1;
	
	cout << "z1 * z2 = " << z2 << endl;
	
	C z4 = z1 * z2;
	
	cout << "z4 = " << z4 << endl;
	
	double x = 4.3;
	
	cout << "x + z4 = " << x+z4 << endl;
	cout << "x * z4 = " << x*z4 << endl;
	
	return 0;
}