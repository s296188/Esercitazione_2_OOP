#pragma once

#include <iostream>
#include <concepts>

using namespace std;

template<typename T> requires std::floating_point<T>

class complex_number
{
	T m_real, m_imag;

public:
	complex_number()                       // costruttore di default
		: m_real(0), m_imag(0) {}
	
	explicit complex_number(T r)           // costruttore user-defined per i reali
		: m_real(r), m_imag (0)
	{
		cout << "Converting constructor called" << endl;
	}
	
	complex_number(T r, T i)               // costruttore user-defined per gli immaginari
		: m_real(r), m_imag(i) {}
	
	T real(void) const {                  // metodo -> parte reale
		return m_real;
	}
	
	T imag(void) const {                  // metodo -> parte immaginaria
		return m_imag;
	}
	
	complex_number conjugate() const {    // metodo -> coniugato
		return complex_number(m_real, -m_imag);
	}
	
	
	complex_number& operator+=(const complex_number& other) {       // Overload di += tra due C
		T r1 = m_real;
		T i1 = m_imag;
		T r2 = other.m_real;
		T i2 = other.m_imag;
		m_real = r1 + r2;
		m_imag = i1 + i2;
		return *this;
	}
	
	
	complex_number& operator+=(const T& other) {                    // += tra C e reale
		m_real += other;
		return *this;
	}
	
	
	complex_number operator+(const complex_number& other) const {   // Overload di + tra due C
		complex_number c = *this;
		c += other;
		return c;
	}
	
	
	complex_number operator+(const T& other) const {                // + tra C e reale
		complex_number c = *this;
		c += other;
		return c;
	}
	
	
	
	complex_number& operator*=(const complex_number& other) {      // Overload di *= tra due C
		T r1 = m_real;
		T i1 = m_imag;
		T r2 = other.m_real;
		T i2 = other.m_imag;
		m_real = r1*r2 - i1*i2;
		m_imag = r2*i1 + r1*i2;
		return *this;
	}
	
	
	complex_number& operator*=(const T& other) {                    // *= tra C e reale
		m_real *= other;
		m_imag *= other;
		return *this;
	}
	
	
	complex_number operator*(const complex_number& other) const {   // Overload di * tra due C
		complex_number c = *this;
		c *= other;
		return c;
	}
	
	
	complex_number operator*(const T& other) const {                // * tra C e reale
		complex_number c = *this;
		c *= other;
		return c;
	}

};


template<typename T>                                                // Overload di <<
ostream&
operator<<(ostream& os, const complex_number<T>& z) {
	os << z.real();
	if (z.imag() > 0)
		os << "+" << z.imag() << "i";
	else if (z.imag() < 0)
		os << z.imag() << "i";
	return os;
}
	
	

template<typename T>
complex_number<T>
operator+(const T& x, const complex_number<T>& z) {
	return z + x;
}
	

template<typename T>
complex_number<T>
operator*(const T& x, const complex_number<T>& z) {
	return z * x;
}




