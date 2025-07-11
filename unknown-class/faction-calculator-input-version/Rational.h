class Rational
{
public:
	Rational(int = 1, int = 1);
	Rational add(const Rational&);
	Rational subtract(const Rational&);
	Rational multiply(const Rational&);
	Rational divide(Rational&);
	void printRational(void);
	void printValue(void);

private:
	int n;
	int d;
	void reducedFraction(void);
};
