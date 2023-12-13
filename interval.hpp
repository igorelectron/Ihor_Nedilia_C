#ifndef _INTERVAL_HPP_
#define _INTERVAL_HPP_

#include <ostream> // std::ostream
#include <istream> // std::istream
#include <stdexcept> // std::invalid_argument
#include <numeric> // std::numeric_limits for infinity value

enum class IntervalKind {
    EMPTY,      // ()
    FINITY,     // (l, r) 
    L_INFINITY, // (-inf, r)
    R_INFINITY, // (l, +inf)
    LR_INFINITY // (-inf, +inf)
};

class Interval {
public:
    Interval() : kind(IntervalKind::EMPTY) {}

    Interval(double l, double r, IntervalKind kind = IntervalKind::FINITY) : kind(kind), l(l), r(r) {
        if (kind == IntervalKind::FINITY && l > r) {
            throw std::invalid_argument("invalid range given: l > r");
        }
    }

    // reat from stdin with hint on stdout
    static Interval input_with_hint(); 

    IntervalKind get_kind() const {
        return kind;
    }
    
    double get_l() const {
        return kind == IntervalKind::L_INFINITY || kind == IntervalKind::LR_INFINITY ? -std::numeric_limits<double>::infinity() : l;
    }
    
    double get_r() const {
        return kind == IntervalKind::R_INFINITY || kind == IntervalKind::LR_INFINITY ? std::numeric_limits<double>::infinity() : r;
    }

    double length() const {
        if (kind == IntervalKind::FINITY) {
            return r - l;
        } 
        if (kind == IntervalKind::EMPTY) {
            return 0.;
        }
        return std::numeric_limits<double>::infinity();
        
    }
protected:
    IntervalKind kind;
    double l{};
    double r{};
};

// io
std::ostream& operator<<(std::ostream& out, const Interval& interval);
std::istream& operator>>(std::istream& in, Interval& interval);

// intersection
Interval operator*(const Interval& a, const Interval& b);

// interval difference (-) and union (+) declared in interval_set.hpp because it use interval set as to return multiple intervals in some cases
// proof (irrepresentable cases for single interval): 
// (1, 2) + (3, 4) = {(1, 2), (3, 4)}
// (1, 4) - (2, 3) = {(1, 2), (3, 4)}

#endif//_INTERVAL_HPP_