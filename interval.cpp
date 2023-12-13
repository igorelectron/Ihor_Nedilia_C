#include <iostream>
#include <cmath> // std::isinf
#include <interval.hpp>

Interval Interval::input_with_hint() {
    double l, r;
    std::cout << "Enter interval range:\nl = " << std::flush;
    std::cin >> l;
    std::cout << "r = " << std::flush;
    std::cin >> r;
    return Interval(l, r);
}

std::ostream& operator<<(std::ostream& out, const Interval& interval) {
    switch (interval.get_kind()) {
    case IntervalKind::EMPTY:
        out << "()";
        break;
    case IntervalKind::L_INFINITY:
        out << "(-inf, " << interval.get_r() << ")";
        break;
    case IntervalKind::R_INFINITY:
        out << "(" << interval.get_l() << ", +inf)";
        break;
    case IntervalKind::LR_INFINITY:
        out << "(-inf, +inf)";
        break;
    default:
        out << "(" << interval.get_l() << ", " << interval.get_r() << ")";
        break;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Interval& interval) {
    double l, r;
    in >> l >> r;
    interval = Interval(l, r);
    return in;
}

// intersection
Interval operator*(const Interval& a, const Interval& b) {
    double c_l = std::max(a.get_l(), b.get_l());
    double c_r = std::min(a.get_r(), b.get_r());

    // empty
    if (std::fabs(c_r - c_l) < 1e-9) {
        return {};
    }

    // new kind
    auto c_kind =
        std::isinf(c_l) && std::isinf(c_r) ? IntervalKind::LR_INFINITY :
        std::isinf(c_l) ? IntervalKind::L_INFINITY :
        std::isinf(c_r) ? IntervalKind::R_INFINITY : IntervalKind::FINITY;

    return Interval(c_l, c_r, c_kind);
}