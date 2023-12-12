#include <iostream>
#include <vector>


class Poly {
public: 
    Poly() noexcept = default;
    Poly(const Poly&) noexcept = default;
    Poly(Poly&&) noexcept = default;
    Poly& operator=(const Poly&) noexcept = default;
    Poly& operator=(Poly&&) noexcept = default;
    ~Poly() noexcept = default;

    template<size_t N>
    Poly(const double (&coefficients)[N]) noexcept : coefficients(coefficients, coefficients+N) {}

    size_t coeff_count() const noexcept {
        return coefficients.size();
    }

    const double& operator[](size_t at) const noexcept {
        return coefficients[at];
    }

    double& operator[](size_t at) noexcept {
        return coefficients[at];
    }

    void push(double coeff) noexcept {
        coefficients.push_back(coeff);
    }
protected:
    std::vector<double> coefficients;
};

std::ostream& operator<<(std::ostream& out, const Poly& p) {
    size_t n = p.coeff_count();
    while (n--) {
        out << p[n] << " * x^" << n;
        if (n != 0) {
            out << " + ";
        }
    }
    return out;
}

int main() {
    const Poly p{{1,2,3,4,5,6}};
    std::cout << p;
}
