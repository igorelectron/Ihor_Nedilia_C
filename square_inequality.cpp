#include <square_inequality.hpp>

IntervalSet SquareInequality::solve() const {
    const double eps = 1e-10;

    IntervalSet set;
    // a x^2 + b x + c <=> 0

    double discriminant = b * b - 4 * a * c;

    if (discriminant > eps) {
        // D > 0
        double sqrt_d = std::sqrt(discriminant);
        double l = (-b - sqrt_d) / 2. / a;
        double r = (-b + sqrt_d) / 2. / a;
        
        // possible in case a < 0
        if (l > r) {
            std::swap(l, r);
        }

        if (kind == EqualityKind::Equal) {
            // 2 points as intervals: { (l, l), (r, r) }
            set.get_intervals().push_back(Interval(l, l, IntervalKind::FINITY));
            set.get_intervals().push_back(Interval(r, r, IntervalKind::FINITY));
        } else if (kind == EqualityKind::NotEqual) {
            // (-inf, +inf) \ { l, r } = { (-inf, l), (l, r), (r, +inf) }
            set.get_intervals().push_back(Interval(0., l, IntervalKind::L_INFINITY));
            set.get_intervals().push_back(Interval(l, r, IntervalKind::FINITY));
            set.get_intervals().push_back(Interval(r, 0., IntervalKind::R_INFINITY));
        } else if ((a > eps && kind == EqualityKind::Less) || (a < eps && kind == EqualityKind::Greater)) {
            set.get_intervals().push_back(Interval(l, r));
        } else {
            set.get_intervals().push_back(Interval(0., l, IntervalKind::L_INFINITY));
            set.get_intervals().push_back(Interval(r, 0., IntervalKind::R_INFINITY));
        }
    } else if (discriminant < -eps) {
        // D < 0
        if ((a > eps && kind == EqualityKind::Greater) || (a < -eps && kind == EqualityKind::Less) || kind == EqualityKind::NotEqual) {
            set.get_intervals().push_back(Interval(0., 0., IntervalKind::LR_INFINITY));
        }
        // otherways empty
    } else {
        // D == 0
        double p = -b / 2. / a;

        if (kind == EqualityKind::Equal) {
            // single solution
            set.get_intervals().push_back(Interval(p, p, IntervalKind::FINITY));
        } else if ((kind == EqualityKind::Less && a < -eps) || (kind == EqualityKind::Greater && a > eps) || kind == EqualityKind::NotEqual) {
            // (-inf, +inf) \ { p } = { (-inf, p), (p, +inf) }
            set.get_intervals().push_back(Interval(0., p, IntervalKind::L_INFINITY));
            set.get_intervals().push_back(Interval(p, 0., IntervalKind::R_INFINITY));
        }
    }

    return set;
}

std::ostream& operator<<(std::ostream& out, const SquareInequality& v) {
    out << v.get_a() << " * x^2 + " << v.get_b() << " * x + " << v.get_c();
    switch (v.get_kind()) {
    case EqualityKind::Equal:
        out << " = 0";
        break;
    case EqualityKind::Less:
        out << " < 0";
        break;
    case EqualityKind::Greater:
        out << " > 0";
        break;
    default:
        out << " != 0";
        break;
    } 
    return out;
}