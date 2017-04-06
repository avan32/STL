/*
for test input
*/
//test 1
/*
5
1 2 
2 1
3 4
5 6
6 7
7
4 5
1 3
9 8
1 4
4 1
6 7
5 4
*/

//test 2
/*
4
1 2
2 3
1 3
1 1
2
1 2
0 1
*/

#include<iostream>
#include <set>
#include <utility>
#include "BinaryRelation.h"


using namespace std;



int main() {

	int n = 10;

	BinaryRelation b(n);

	cout << "\n\n\t\tINPUT b" << endl;
	cin >> b;

	BinaryRelation c(n);

	cout << "\n\n\t\tINPUT c" << endl;
	cin >> c;

	cout << "\n\n\t\tOUTPUT b = b+c" << endl;

	cout <<  b + c;

	b = b + c;


	cout << "\n\n\tb isX  - methods\n" << endl;
	if (b.isAntisymmetric())cout << " Antisymmetric" << endl;
	else cout << " not Antisymmetric" << endl;
	if (b.isEquivalence())cout << " Equivalence" << endl;
	else cout << " not Equivalence" << endl;
	if (b.isOrder())cout << " Order" << endl;
	else cout << " not Order" << endl;
	if (b.isReflexive())cout << " Reflexive" << endl;
	else cout << " not Reflexive" << endl;
	if (b.isSymmetric())cout << " Symmetric" << endl;
	else cout << " not Symmetric" << endl;
	if (b.isTransitive())cout << " Transitive" << endl;
	else cout << " not Transitive" << endl;
	cout << "\tend b isX  - methods\n" << endl;

	BinaryRelation d = b.operator*();

	cout << "\n\n\t\tOUTOUT  d = b.operator*()" << endl;
	cout << d;

	cout << "\n\n\t\tOUTOUT b*c" << endl;
	cout << b*c;

	cout << "\n\n\t\tOUTOUT b==b" << endl;
	cout << (b == b);

	cout << "\n\n\t\tOUTOUT b!=b" << endl;
	cout << (b != b);

	cout << "\n\n\t\tOUTOUT b!=c" << endl;
	cout << (b != c) << endl;

	return 0;
}