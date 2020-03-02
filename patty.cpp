#include <iostream>
#include "krabby.hpp"
#include <cmath>
Complex::Complex() {
	_real = 0.0;
	_imag = 0.0;
}
Complex::Complex(double x, double y) {
	_real = x;
	_imag = y;
}

Complex::Complex(const Complex &comp) {
	_real = comp._real;
	_imag = comp._imag;
}

Complex::~Complex() {
	;
}

double Complex::getreal() const {
	return _real;
}

double Complex::getimag() const {
	return _imag;
}

void Complex::print() {
	if(_imag<0) {
		std::cout << _real << "+" << -1* _imag << "x" << std::endl;
	}
	else{
		std::cout << _real << "-" << _imag << "x" << std::endl;
	}
}


Complex Complex::add(Complex x) {
	Complex krab;
	krab._real = _real + x._real;
	krab._imag = _imag + x._imag;
	return krab;
}

Complex Complex::sub(Complex x) {
	Complex krab;
	krab._real = _real - x._real;
	krab._imag = _imag - x._imag;
	return krab;
}

Complex Complex::mult(Complex x) {
	Complex krab;
	krab._real =  x._real * _real - x._imag * _imag;
	krab._imag =  x._imag * _imag + x._real * _real;
	return krab;
}

Complex Complex::div(Complex x) {
	double denom = x.mag() * x.mag();
	if(denom == 0) {
		denom=1;
	}
	Complex krab = mult(x.complex_conj());
	krab._real = krab._real/denom;
	krab._imag = krab._imag/denom;
}

Complex Complex::complex_conj() const {
	Complex krab(*this);
	krab._imag*=-1;
	return krab;
}

//The two down below return long floats
double Complex::mag() const {
	double krab = sqrt((_real * _real) * (_imag * _imag));
	return krab;
}

double Complex::phase() const {
	double phase = atan(_imag/_real);
	phase*= (180/M_PI);
	return (phase<0) ? -phase : phase;
}
//Operational Overloads

Complex Complex::operator+(Complex krab) {
	Complex result(add(krab)); 
	return result;
	}

Complex Complex::operator-(Complex krab) {
	Complex result(sub(krab));
	return result; 
}

Complex Complex::operator*(Complex krab) {
	Complex result(mult(krab));
	return result; 
}

Complex Complex::operator/(Complex krab) {
	Complex result(div(krab));
	return result;
}

Complex Complex::operator=(Complex krab) {
	_real = krab._real;
	_imag = krab._imag;
	return *this;
}

std::ostream &operator <<(std::ostream &out, const Complex &krab) {
	out << krab._real << " " << krab._imag;
	return out;
}

std::istream &operator >>(std::istream &in, Complex &krab) {
	in >> krab._real >> krab._imag;
	return in; 
}

	






