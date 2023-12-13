#include <iostream>
#include <interval_set.hpp>

IntervalSet IntervalSet::input_with_hint() {
    IntervalSet set;

    std::cout << "Enter intervals count:\n" << std::flush;
    unsigned n;
    std::cin >> n;
    for (unsigned i = 0; i < n; i++) {
        set.intervals.push_back(Interval::input_with_hint());
    }

    return set;
} 

std::ostream& operator<<(std::ostream& out, const IntervalSet& interval_set) {
    auto& intervals = interval_set.get_intervals();
    out << "{";
    if (!intervals.empty()) {
        out << intervals[0];
        for (size_t i = 1; i < intervals.size(); i++) {
            out << ", " << intervals[i];
        }
    }
    out << "}";
    return out;
}

std::istream& operator>>(std::istream& in, IntervalSet& interval_set) {
    auto& intervals = interval_set.get_intervals();
    intervals.clear();

    unsigned n;
    in >> n;
    for (unsigned i = 0; i < n; i++) {
        Interval v;
        in >> v;
        intervals.push_back(v);
    }

    return in;
}

// interval union
IntervalSet operator+(const Interval& a, const Interval& b) {
    double a_l = a.get_l();
    double a_r = a.get_r();
    double b_l = b.get_l();
    double b_r = b.get_r();
    
    IntervalSet ret;
    auto& i = ret.get_intervals();

    if (b_l > a_r || a_l > b_r) {
        // no intersection -> add both to set (if non-empty)
        if (a.get_kind() != IntervalKind::EMPTY) i.push_back(a);
        if (a.get_kind() != IntervalKind::EMPTY) i.push_back(b);
    } else {
        // intersection -> single interval in set (if non-empty)
        double l = std::min(a_l, b_l);
        double r = std::max(a_r, b_r);

        auto kind =
            std::isinf(l) && std::isinf(r) ? IntervalKind::LR_INFINITY :
            std::isinf(l) ? IntervalKind::L_INFINITY :
            std::isinf(r) ? IntervalKind::R_INFINITY : IntervalKind::FINITY;

        if (std::abs(r - l) > 1e-9) i.push_back(Interval(l, r, kind));
    }

    return ret;
}

// interval difference
IntervalSet operator-(const Interval& a, const Interval& b) {
    double a_l = a.get_l();
    double a_r = a.get_r();
    double b_l = b.get_l();
    double b_r = b.get_r();
    
    IntervalSet ret;
    auto& i = ret.get_intervals();

    if (b_r < a_l || a_r < b_l) {
        // no intersection, result equal to a
        if (a.get_kind() != IntervalKind::EMPTY) i.push_back(a);
    } else if (b_l < a_l && a_r < b_r) {
        // a inside b 
        // ret is empty
    } else if (a_l < b_l && b_r < a_r) {
        // b splits a into 2 parts

        auto l_kind =
            std::isinf(a_l) && std::isinf(b_l) ? IntervalKind::LR_INFINITY :
            std::isinf(a_l) ? IntervalKind::L_INFINITY :
            std::isinf(b_l) ? IntervalKind::R_INFINITY : IntervalKind::FINITY;

        auto r_kind =
            std::isinf(b_r) && std::isinf(a_r) ? IntervalKind::LR_INFINITY :
            std::isinf(b_r) ? IntervalKind::L_INFINITY :
            std::isinf(a_r) ? IntervalKind::R_INFINITY : IntervalKind::FINITY;

        i.push_back(Interval(a_l, b_l, l_kind));
        i.push_back(Interval(b_r, a_r, r_kind));
    } else {
        // b cut off one part of a

        double l = a_l;
        double r = a_r;

        if (a_l <= b_l) {
            r = b_l;
        } else {
            // b_r < a_r
            l = b_r;
        }

        auto kind =
            std::isinf(l) && std::isinf(r) ? IntervalKind::LR_INFINITY :
            std::isinf(l) ? IntervalKind::L_INFINITY :
            std::isinf(r) ? IntervalKind::R_INFINITY : IntervalKind::FINITY;
        
        if (std::abs(r - l) > 1e-9) i.push_back(Interval(l, r, kind));
    }

    return ret;
}

// intersection
IntervalSet operator*(const IntervalSet& a, const IntervalSet& b) {
    IntervalSet result;
    auto& res = result.get_intervals();
    for (auto& i_a : a.get_intervals()) {
        for (auto& i_b : b.get_intervals()) {
            auto i = i_a * i_b;
            if (i.get_kind() != IntervalKind::EMPTY) {
                res.push_back(i);
            }
        }
    }
    return result;
}

// union
IntervalSet operator+(const IntervalSet& a, const IntervalSet& b) {
    // TODO fix a bit?
    IntervalSet result;
    auto& res = result.get_intervals();
    for (auto& i_a : a.get_intervals()) {
        for (auto& i_b : b.get_intervals()) {
            auto ab = i_a + i_b;
            for (auto& v : ab.get_intervals()) {
                res.push_back(v);
            }
        }
    }
    return result;
}

// difference
IntervalSet operator-(const IntervalSet& a, const IntervalSet& b) {
    IntervalSet result;
    auto& res = result.get_intervals();
    for (auto& i_a : a.get_intervals()) {
        std::vector<Interval> diff = { i_a };
        // diff i_a with all elements of b
        // in total max (|b|) * (|b| + 1) iterations of inner loop
        for (auto& i_b : b.get_intervals()) {
            std::vector<Interval> new_diff;
            for (auto& el : diff) {
                // 1 or 2 iterations
                auto d = el - i_b;
                for (auto& v : d.get_intervals()) {
                    new_diff.push_back(v);
                }
            }

            diff = new_diff;
        }

        for (auto& v : diff) {
            res.push_back(v);
        }
    }
    return result;
}
