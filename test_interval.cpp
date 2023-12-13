#include "tests_common.hpp"

int main() {
    Interval a = Interval(-3, 4, IntervalKind::FINITY);       // (-3, 4)
    Interval b = Interval(-3, 4, IntervalKind::L_INFINITY);   // (-inf, 4)
    Interval c = Interval(-3, 4, IntervalKind::R_INFINITY);   // (-4, +inf)
    Interval d = Interval(-3, 4, IntervalKind::LR_INFINITY);  // (-inf, +inf)

    const double inf = std::numeric_limits<double>::infinity();

    assert_equal(a.length(), 7);
    assert_equal(b.length(), inf);
    assert_equal(c.length(), inf);
    assert_equal(d.length(), inf);

    assert_equal(a.get_l(), -3);
    assert_equal(b.get_l(), -inf);
    assert_equal(c.get_l(), -3);
    assert_equal(d.get_l(), -inf);

    assert_equal(a.get_r(), 4);
    assert_equal(b.get_r(), 4);
    assert_equal(c.get_r(), inf);
    assert_equal(d.get_r(), inf);

    assert_equal(a * b, a);
    assert_equal(b * c, a);
    assert_equal(a * d, a);
    assert_equal(c * d, d * c);

    std::cout << "SUCCESS\n";
}