#include <iostream>
#include <list>
#include "Polynomial.h"
#include <math.h>

using namespace std;

Polynomial Polynomial::operator*(const Monomial & m) const
{
	Polynomial result(*this);

	Iterator it = result.polynomial_.begin();
	while (it != result.polynomial_.end()) {
		it->coef_ *= m.coef_;
		it->exp_ += m.exp_;
		it++;
	}

	return result;
}

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const Polynomial & other)
{
	CIterator it2 = other.polynomial_.begin();
	while (it2 != other.polynomial_.end()) {
		this->polynomial_.push_back(Monomial(it2->coef_, it2->exp_));
		it2++;

	}
}

Polynomial & Polynomial::operator=(const Polynomial & other)
{
	CIterator it2 = other.polynomial_.begin();

	while (!this->polynomial_.empty()) this->polynomial_.pop_front();
	while (it2 != other.polynomial_.end()) {
		this->polynomial_.push_back(Monomial(it2->coef_, it2->exp_));
		it2++;

	}
	return *this;
}

bool Polynomial::operator==(const Polynomial & other) const
{
	CIterator it1 = this->polynomial_.begin();
	CIterator it2 = other.polynomial_.begin();

	while (it1 != this->polynomial_.end() && it2 != other.polynomial_.end()) {
		if (it1->exp_ != it2->exp_ || it1->coef_ != it2->coef_) return false;
		it1++;
		it2++;
	}
	if (it1 != this->polynomial_.end() || it2 != other.polynomial_.end()) return false;

	return true;
}

bool Polynomial::operator!=(const Polynomial & other) const
{
	return !(*this == other);
}

double Polynomial::operator()(double x) const
{
	double result = 0.0;
	CIterator it = this->polynomial_.begin();

	while (it != this->polynomial_.end())
	{
		result += (it->coef_*(pow(x, it->exp_)));
		it++;
	}

	return result;
}

Polynomial Polynomial::operator+(const Polynomial & other) const
{
	Polynomial result;
	CIterator it1 = this->polynomial_.begin();
	CIterator it2 = other.polynomial_.begin();

	while (it1 != this->polynomial_.end() && it2 != other.polynomial_.end())
	{
		if (it1->exp_ > it2->exp_) {
			result.polynomial_.push_back(*it1++);
			continue;
		}

		if (it1->exp_ < it2->exp_) {
			result.polynomial_.push_back(*it2++);
			continue;
		}

		if (it1->coef_ + it2->coef_)
			result.polynomial_.push_back(Monomial(it1->coef_ + it2->coef_, it1->exp_));

		it1++; it2++;
	}
	while (it1 != this->polynomial_.end())
		result.polynomial_.push_back(*it1++);

	while (it2 != other.polynomial_.end())
		result.polynomial_.push_back(*it2++);

	return result;
}

Polynomial Polynomial::operator-(const Polynomial & other) const
{
	Polynomial result;
	CIterator it1 = this->polynomial_.begin();
	CIterator it2 = other.polynomial_.begin();

	while (it1 != this->polynomial_.end() && it2 != other.polynomial_.end())
	{
		if (it1->exp_ > it2->exp_) {
			result.polynomial_.push_back(*it1++);
			continue;
		}

		if (it1->exp_ < it2->exp_) {
			result.polynomial_.push_back(Monomial(-it2->coef_, it2->exp_));
			it2++;
			continue;
		}

		if (it1->coef_ - it2->coef_)
			result.polynomial_.push_back(Monomial(it1->coef_ - it2->coef_, it1->exp_));

		it1++; it2++;
	}
	while (it1 != this->polynomial_.end())
		result.polynomial_.push_back(*it1++);

	while (it2 != other.polynomial_.end()) {

		result.polynomial_.push_back(Monomial(-it2->coef_, it2->exp_));
		it2++;
	}
	return result;
}

Polynomial Polynomial::operator*(const Polynomial & other) const
{
	Polynomial result;
	//CIterator it1 = this->polynomial_.begin();
	CIterator it2 = other.polynomial_.begin();
	while (it2 != other.polynomial_.end()) { result = result + *this * Monomial(it2->coef_, it2->exp_); it2++; };
	return result;
}

Polynomial Polynomial::operator/(const Polynomial & other) const
{
	Polynomial result;
	Polynomial mnacord(*this);
	//Polynomial next(*this);


	Iterator it2 = mnacord.polynomial_.begin();
	CIterator it3 = other.polynomial_.begin();

	while (it3->exp_ <= it2->exp_) {
		int exp = it2->exp_ - it3->exp_;
		double coef = it2->coef_ / it3->coef_;
		mnacord = mnacord - other*Monomial(coef, exp);
		cout << endl;
		result.polynomial_.push_back(Monomial(coef, exp));

		it2 = mnacord.polynomial_.begin();
		it3 = other.polynomial_.begin();

	}

	return result;
}

Polynomial Polynomial::operator%(const Polynomial & other) const
{
	Polynomial mnacord(*this);
	//Polynomial next(*this);


	Iterator it2 = mnacord.polynomial_.begin();
	CIterator it3 = other.polynomial_.begin();

	while (it3->exp_ <= it2->exp_) {
		int exp = it2->exp_ - it3->exp_;
		double coef = it2->coef_ / it3->coef_;
		mnacord = mnacord - other*Monomial(coef, exp);
		cout << endl;


		it2 = mnacord.polynomial_.begin();
		it3 = other.polynomial_.begin();

	}

	return mnacord;
}

istream & operator>>(std::istream & input, Polynomial & p)
{
	cout << "input lenght :: ";

	int l;
	cin >> l;

	cout << "\tUpload a decreasing sequence\n";
	int coef,
		exp;

	for (int i = 0; i < l; i++) {
		cout << i + 1 << ") inputs ceof and exp\n\t";
		cin >> coef >> exp;
		p.polynomial_.push_back(Polynomial::Monomial(coef, exp));
	}
	return input;
}

ostream & operator<<(std::ostream & output, const Polynomial & poly)
{
	for (Polynomial::CIterator it = poly.polynomial_.begin();
	it != poly.polynomial_.end();
		it++
		)
		output << "coef=" << it->coef_ << ", exp=" << it->exp_ << endl;
	return output;
}



