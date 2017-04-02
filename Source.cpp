/*
*	30.03.2017
*
*	Armsoft student 
*	Gor Kirakosyan 
*/

//test input inout_cin 
/*
4 
2 7 
-4 3 
5 2 
1 1 
*/

#include <list>
#include <iostream>
#include "Polynomial.h"

int main(int argc, char* argv[])
{
	//test input_cin
	//you can input with cin 
	/*
	Polynomial input_cin;
	cin >> input_cin;
	cout << "\ninput_cin\n" << input_cin << endl ;
	*/
	
	//you can iput Polynomial with cin>> or you can use set_polynomial_ method


	typedef Polynomial::Monomial monomial;//if you want you can delete this line and Polynomial::Monomial do private my code will be work 

	Polynomial first;
	Polynomial second;

	//i write set_polynomial_ method for set qucklie if you don't want to write input
	first.set_polynomial_(monomial(3, 5));
	first.set_polynomial_(monomial(-3, 2));
	first.set_polynomial_(monomial(5, 1));

	second.set_polynomial_(monomial(7, 5));
	second.set_polynomial_(monomial(-3, 2));
	second.set_polynomial_(monomial(-10, 1));
	second.set_polynomial_(monomial(-8, 0));

	cout << "first\n" << first << endl << "second\n" << second << endl
		<< "\nfirst+second\n" << first + second << endl
		<< "\nfirst-second\n" << first - second << endl
		<< "\nfirst*second\n" << first * second << endl
		<< "\nfirst/second\n" << first / second << endl
		<< "\nfirst%second\n" << first % second << endl;

	cout << "this is a ((first / second)*second + (first%second)) who equals first \n"
		<< ((first / second)*second + (first%second)) << endl;


	cout << "\n\nfirst(1) = " << first(1) << endl
		<< "first(2) = " << first(2) << endl
		<< "first(0.5) = " << first(0.5) << endl
		<< "first(-1) = " << first(-1) << endl
		<< "\nfirst\n\t\b|\n\t\bv\n" << first;
	cout << "----------------------" << endl;

	for (int i = 0; i < 7; i++)
		cout << "\a";

	cin.get();
	return 0;
}
