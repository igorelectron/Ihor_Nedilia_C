#include <iostream>
#include <vector>
#include <cmath>

class PolynomialError : public std::exception
{
public:
    explicit PolynomialError(const char *message) : message(message) {}

    const char *what() const noexcept override
    {
        return message;
    }

private:
    const char *message;
};

class Polynomial
{
public:
    Polynomial(int degree, const std::vector<double> &coefficients)
        : degree(degree), coefficients(coefficients)
    {
        if (degree < 0)
        {
            throw PolynomialError("Degree must be a non-negative integer.");
        }
        if (coefficients.size() != degree + 1)
        {
            throw PolynomialError("Number of coefficients must match the degree.");
        }
    }

    static Polynomial inputFromConsole()
    {
        int degree;
        std::cout << "Enter the degree of the polynomial: ";
        std::cin >> degree;

        std::vector<double> coefficients(degree + 1);
        std::cout << "Enter the coefficients starting from the highest degree term:\n";
        for (int i = degree; i >= 0; --i)
        {
            std::cout << "Coefficient for x^" << i << ": ";
            std::cin >> coefficients[i];
        }

        return Polynomial(degree, coefficients);
    }

    void print() const
    {
        std::cout << "Polynomial: ";
        for (int i = degree; i >= 0; --i)
        {
            if (coefficients[i] != 0.0)
            {
                std::cout << coefficients[i];
                if (i > 0)
                {
                    std::cout << "x^" << i << " + ";
                }
            }
        }
        std::cout << '\n';
    }

    double evaluate(double x) const
    {
        double result = 0.0;
        for (int i = degree; i >= 0; --i)
        {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }

    Polynomial derivative() const
    {
        if (degree == 0)
        {
            return Polynomial(0, {0.0});
        }

        std::vector<double> derivativeCoefficients(degree);
        for (int i = degree - 1; i >= 0; --i)
        {
            derivativeCoefficients[i] = coefficients[i + 1] * (i + 1);
        }

        return Polynomial(degree - 1, derivativeCoefficients);
    }

    Polynomial operator+(const Polynomial &other) const
    {
        int resultDegree = std::max(degree, other.degree);
        std::vector<double> resultCoefficients(resultDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i)
        {
            resultCoefficients[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i)
        {
            resultCoefficients[i] += other.coefficients[i];
        }

        return Polynomial(resultDegree, resultCoefficients);
    }

    Polynomial operator-(const Polynomial &other) const
    {
        int resultDegree = std::max(degree, other.degree);
        std::vector<double> resultCoefficients(resultDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i)
        {
            resultCoefficients[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i)
        {
            resultCoefficients[i] -= other.coefficients[i];
        }

        return Polynomial(resultDegree, resultCoefficients);
    }

    Polynomial operator*(const Polynomial &other) const
    {
        int resultDegree = degree + other.degree;
        std::vector<double> resultCoefficients(resultDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i)
        {
            for (int j = 0; j <= other.degree; ++j)
            {
                resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultDegree, resultCoefficients);
    }

private:
    int degree;
    std::vector<double> coefficients;
};

int main()
{
    try
    {
        Polynomial poly = Polynomial::inputFromConsole();
        poly.print();

        double x;
        std::cout << "Enter a value for x: ";
        std::cin >> x;
        std::cout << "Result: " << poly.evaluate(x) << '\n';

        Polynomial derivative = poly.derivative();
        std::cout << "Derivative: ";
        derivative.print();

        Polynomial poly2 = Polynomial::inputFromConsole();
        poly2.print();

        Polynomial sum = poly + poly2;
        std::cout << "Sum: ";
        sum.print();

        Polynomial difference = poly - poly2;
        std::cout << "Difference: ";
        difference.print();

        Polynomial product = poly * poly2;
        std::cout << "Product: ";
        product.print();
    }
    catch (const PolynomialError &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
