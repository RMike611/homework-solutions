#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int d;

	cout << "Enter a numerator: ";
	cin >> a;
	cout << "Enter a denominator: ";
	cin >> b;
	cout << "Enter a second numerator: ";
	cin >> c;
	cout << "Enter a second denominator: ";
	cin >> d;
	cout << endl;
	
	Rational firstFraction(a, b), secondFraction(c, d), base;

	firstFraction.printRational();
	cout << " + ";
	secondFraction.printRational();
	base = firstFraction.add(secondFraction);
	cout << " = ";
	base.printRational();
	cout << endl;
	cout << "The floating-point format is: ";
	base.printValue();
	cout << endl << endl;

	firstFraction.printRational();
	cout << " - ";
	secondFraction.printRational();
	base = firstFraction.subtract(secondFraction);
	cout << " = ";
	base.printRational();
	cout << endl;
	cout << "The floating-point format is: ";
	base.printValue();
	cout << endl << endl;

	firstFraction.printRational();
	cout << " * ";
	secondFraction.printRational();
	base = firstFraction.multiply(secondFraction);
	cout << " = ";
	base.printRational();
	cout << endl;
	cout << "The floating-point format is: ";
	base.printValue();
	cout << endl << endl;

	firstFraction.printRational();
	cout << " / ";
	secondFraction.printRational();
	base = firstFraction.divide(secondFraction);
	cout << " = ";
	base.printRational();
	cout << endl;
	cout << "The floating-point format is: ";
	base.printValue();
	cout << endl;

	return 0;
}
