#include "tests_common.hpp"

int main() {
    Interval a = Interval(-3, 4, IntervalKind::FINITY);
    Interval b = Interval(5, 6, IntervalKind::FINITY);
    Interval c = Interval(-10, -2, IntervalKind::FINITY);

    Interval e = Interval(-3, 4, IntervalKind::L_INFINITY);
    Interval f = Interval(-3, 4, IntervalKind::R_INFINITY);
    Interval g = Interval(0., 0., IntervalKind::LR_INFINITY);

    // interval operations + -

    assert_equal(a + b, IntervalSet({a, b}));
    assert_equal(a + c, IntervalSet({Interval(-10, 4, IntervalKind::FINITY)}));
    assert_equal(a + e, IntervalSet({e}));
    assert_equal(a + f, IntervalSet({f}));
    assert_equal(a + g, IntervalSet({g}));

    assert_equal(c - a, IntervalSet({Interval(-10, -3, IntervalKind::FINITY)}));
    assert_equal(c - b, IntervalSet({c}));
    assert_equal(a - c, IntervalSet({Interval(-2, 4, IntervalKind::FINITY)}));

    assert_equal(a - g, IntervalSet());
    assert_equal(c - f, IntervalSet({Interval(-10, -3, IntervalKind::FINITY)}));
    assert_equal(c - e, IntervalSet());
  
    // interval set operations * + -

    assert_equal(IntervalSet({a}) + IntervalSet({b}), IntervalSet({a, b}));
    assert_equal(IntervalSet({a}) + IntervalSet({c}), IntervalSet({Interval(-10, 4, IntervalKind::FINITY)}));
    assert_equal(IntervalSet({a}) + IntervalSet({e}), IntervalSet({e}));
    assert_equal(IntervalSet({a}) + IntervalSet({f}), IntervalSet({f}));
    assert_equal(IntervalSet({a}) + IntervalSet({g}), IntervalSet({g}));

    assert_equal(IntervalSet({c}) - IntervalSet({a}), IntervalSet({Interval(-10, -3, IntervalKind::FINITY)}));
    assert_equal(IntervalSet({c}) - IntervalSet({b}), IntervalSet({c}));
    assert_equal(IntervalSet({a}) - IntervalSet({c}), IntervalSet({Interval(-2, 4, IntervalKind::FINITY)}));

    assert_equal(IntervalSet({a}) - IntervalSet({g}), IntervalSet());
    assert_equal(IntervalSet({c}) - IntervalSet({f}), IntervalSet({Interval(-10, -3, IntervalKind::FINITY)}));
    assert_equal(IntervalSet({c}) - IntervalSet({e}), IntervalSet());

    auto t = IntervalSet({a, b});

    assert_equal(t.length(), 8);

    std::cout << "SUCCESS\n";
}