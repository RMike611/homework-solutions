#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
	Rational n(8, 9), d(2, 6), x;

	n.printRational();
	cout << " + ";
	d.printRational();
	x = n.add(d);
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printFloatingrational();
	cout << "\n\n";

	n.printRational();
	cout << " - ";
	d.printRational();
	x = n.subtract(d);
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printFloatingrational();
	cout << "\n\n";

	n.printRational();
	cout << " * ";
	d.printRational();
	x = n.multiply(d);
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printFloatingrational();
	cout << "\n\n";

	n.printRational();
	cout << " / ";
	d.printRational();
	x = n.divide(d);
	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printFloatingrational();
	cout << endl;

	return 0;
}
