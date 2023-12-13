#ifndef _SQUARE_INEQUALITY_HPP_
#define _SQUARE_INEQUALITY_HPP_

#include <cmath> // std::fabs

#include "interval_set.hpp"

enum class EqualityKind {
    Less,
    Equal,
    Greater,
    NotEqual,

    // Because all our intervals contains floating-point numbers they can't 
    // have exact bounds so `>` & `>=` has no difference in this case 
    LessEqual = Less,
    GreaterEqual = Greater,
};

class SquareInequality {
public:
    SquareInequality(double a, double b, double c, EqualityKind kind = EqualityKind::Equal) : a(a), b(b), c(c), kind(kind) {
        if (std::fabs(a) < 1e-10) {
            throw std::invalid_argument("invalid SquareInequality argument: `a` must be non-zero");
        }
    }

    IntervalSet solve() const;

    double get_a() const { 
        return a; 
    }

    double get_b() const { 
        return b; 
    }

    double get_c() const { 
        return c; 
    }
    
    EqualityKind get_kind() const { 
        return kind; 
    }
protected:
    // a x^2 + b x + c <=> 0
    double a, b, c;
    EqualityKind kind;
};

std::ostream& operator<<(std::ostream& out, const SquareInequality& v);

#endif//_SQUARE_INEQUALITY_HPP_