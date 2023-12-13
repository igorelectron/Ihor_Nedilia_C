#include <iostream>
#include <string>
#include <square_inequality.hpp>

int main() {
    std::cout << "Info: Equations are represented by 3 coefficients (a, b, c) and a comparison operator ? (one of == != > <) such that a * x^2 + b^x + c ? 0 evaluates to true\n";
    std::cout << "Enter number of equations in system:\nn = " << std::flush;
    unsigned n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    std::vector<SquareInequality> equations;

    std::string op;

    for (unsigned i = 0; i < n; i++) {
        double a, b, c;
        std::cout << "a b c = " << std::flush;
        std::cin >> a >> b >> c;

        std::cout << "operator ? = " << std::flush;
        std::cin >> op;

        EqualityKind eq = 
            op == "==" ? EqualityKind::Equal :
            op == "!=" ? EqualityKind::NotEqual :
            op == ">" ? EqualityKind::Greater : EqualityKind::Less;

        equations.push_back(SquareInequality(a, b, c, eq));
    }

    IntervalSet solution = equations[0].solve();

    for (size_t i = 1; i < equations.size(); i++) {
        solution = solution * equations[i].solve();
    }

    std::cout << "Solution is:\n" << solution << std::endl;
}