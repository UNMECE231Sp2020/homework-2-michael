#include <iostream>

class Complex {
	private:
		double _real;
		double _imag;
	public:
		Complex();

		Complex(double x, double y);

		Complex(const Complex &comp);

		~Complex();

		double getreal() const;
		double getimag() const;
		void print();
		
		Complex add(Complex x);
		Complex sub(Complex x);	
		Complex mult(Complex x);
		Complex div(Complex x);

		Complex complex_conj() const;
		double mag() const;
		double phase() const;


		Complex operator+(Complex krab);
		Complex operator-(Complex krab);
		Complex operator*(Complex krab);
		Complex operator/(Complex krab);
		Complex operator=(Complex krab);
		friend std::ostream &operator<<(std::ostream &out, const Complex &krab);
		friend std::istream &operator>>(std::istream &in, Complex &krab); 

};	
