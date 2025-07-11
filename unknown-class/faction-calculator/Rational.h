class Rational
{
public:
	Rational(int = 1, int = 2);
	Rational add(const Rational&);
	Rational subtract(const Rational&);
	Rational multiply(const Rational&);
	Rational divide(Rational&);
	void printRational(void);
	void printFloatingrational(void);
private:
	int n;
	int d;
	void reducedFraction(void);
};

