#pragma once
#include <iostream>
#include <list>
using namespace std;

//***** THE CLASS POLYNOMIAL *****

class Polynomial {
public:
	//struct Monomial
	struct Monomial
	{
		double	coef_;
		int		exp_;
		Monomial() {}

		Monomial(double coef, int exp) : coef_(coef), exp_(exp) {}
	};

	//types
	typedef list<Monomial>							ListOfMonomials;
	typedef ListOfMonomials::iterator				Iterator;
	typedef ListOfMonomials::const_iterator			CIterator;

	Polynomial operator*(const Monomial& m)const; //auxiliary private function: returns (*this) multiplied by m

public:
	Polynomial();
	Polynomial(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);

	bool	operator==(const Polynomial& other)const;
	bool	operator!=(const Polynomial& other)const;

	double     operator()(double x)const; //returns the value of (*this) at x 

	Polynomial operator+(const Polynomial& other)const;
	Polynomial operator-(const Polynomial& other)const;
	Polynomial operator*(const Polynomial& other)const;
	Polynomial operator/(const Polynomial& other)const;
	Polynomial operator%(const Polynomial& other)const;

	//	this is a don't must be
	//	you can input Polynomial with cin
	void set_polynomial_(Monomial m) {
		polynomial_.push_back(m);
	}

private:
	ListOfMonomials	 polynomial_;

	friend istream& operator>>(std::istream& input, Polynomial& p);
	friend ostream& operator<<(std::ostream& output, const Polynomial& p);

};

