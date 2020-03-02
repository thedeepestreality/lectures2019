#include <iostream>

class Complex
{
private:
	double _re;
	double _im;
public:
	Complex(double re = 0, double im = 0) : _re(re), _im(im) {}
	Complex(const Complex& src) : Complex(src._re, src._im) {}
	static Complex sum(const Complex& zl, const Complex& zr)
	{
		return Complex(zl._re + zr._re, zl._im + zr._im);
	}

	void print() const
	{
		std::cout << _re << "+(" << _im << ")i";
	}

	double abs() const
	{
		return sqrt(_re * _re + _im * _im);
	}

	Complex sum(const Complex& right)
	{
		return Complex(_re + right._re, _im + right._im);
	}

	Complex operator+(const Complex& right)
	{
		return Complex(_re + right._re, _im + right._im);
	}

	Complex operator*(const Complex& right)
	{
		return Complex(_re*right._re - _im * right._im,
					   _re*right._im + _im * right._re);
	}

	Complex& operator+=(const Complex& right)
	{
		_re += right._re;
		_im += right._im;
		return *this;
	}

	Complex& operator++()
	{
		_re += 1;
		return *this;
	}

	Complex operator++(int)
	{
		Complex c = *this;
		_re += 1;
		return c;
	}

	bool operator>(const Complex& right)
	{
		return abs() > right.abs();
	}

	bool operator==(const Complex& right)
	{
		return (_re == right._re) && (_im == right._im);
	}

	bool operator<(const Complex& right)
	{
		return !(*this > right) && !(*this == right);
	}

	Complex operator<<(int shift)
	{
		return *this;
	}

	Complex operator-()
	{
		return Complex(-_re, -_im);
	}

	double real() const { return _re; }
	double imag() const { return _im; }

	friend Complex sum(const Complex&, const Complex&);
	friend std::ostream& operator<<(std::ostream& out, const Complex& z)
	{
		out << z._re << "+(" << z._im << ")i";
		return out;
	}
};

Complex sum(const Complex& zl, const Complex& zr)
{
	return Complex(zl._re + zr._re, zl._im + zr._im);
}

Complex operator+(const Complex& zl, const Complex& zr)
{
	std::cout << "complex + complex" << std::endl;
	return Complex(zl.real() + zr.real(), zl.imag() + zr.imag());
}

Complex operator+(int left, const Complex& zr)
{
	std::cout << "int + complex" << std::endl;
	return Complex(left + zr.real(), left + zr.imag());
}

class Poly
{
private:
	int _degree;
	double* _coeffs;
	double& at(int idx) const
	{
		if (idx < 0 || idx > _degree)
			throw "out of bounds";
		return _coeffs[idx];
	}
public:
	Poly() : _degree(0), _coeffs(new double[1])
	{
		_coeffs[0] = 1;
	}
	Poly(int degree) : _degree(degree),
					   _coeffs(new double[degree+1]){}

	Poly(const Poly& p) : _degree(p._degree),
				_coeffs(new double[_degree + 1])
	{
		std::cout << "Poly copy constructor" << std::endl;
		for (int i = 0; i <= _degree; ++i)
			_coeffs[i] = p._coeffs[i];
	}

	Poly& operator=(const Poly& p)
	{
		if (this == &p)
			return *this;
		std::cout << "Poly assignment" << std::endl;
		_degree = p._degree;
		delete[] _coeffs;
		_coeffs = new double[_degree+1];
		for (int i = 0; i <= _degree; ++i)
			_coeffs[i] = p._coeffs[i];
		return *this;
	}

	~Poly()
	{
		delete[] _coeffs;
	}

	double& operator[](int idx) const
	{
		return at(idx);
	}

	Complex operator()(const Complex& x) const
	{
		Complex s(0, 0);
		Complex d = 1;
		for (int i = 0; i <= _degree; ++i)
		{
			s += d * _coeffs[i];
			d = d * x;
		}

		return s;
	}

};

int main()
{
	Complex c(1, -1);
	Complex res = c.sum(Complex(2.5, 0.6));
	res = Complex::sum(c, res);
	res = sum(c, res);
	Complex s = 1.0 + c;
	Complex x = -s;

	std::cout << Complex(1, 2) + 1 << std::endl;

	Poly p(2);
	p[0] = 1;
	p[1] = 2;
	p[2] = 1;

	std::cout << p(1) << std::endl;

	Poly p2 = p;
	p2 = p2;

	system("pause");
	return 0;
}