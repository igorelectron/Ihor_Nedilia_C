#include "tests_common.hpp"

int main() {
    // all points > 0
    assert_equal(SquareInequality(1, 1, 1, EqualityKind::Equal).solve(), IntervalSet());
    assert_equal(SquareInequality(1, 1, 1, EqualityKind::Less).solve(), IntervalSet());
    assert_equal(SquareInequality(1, 1, 1, EqualityKind::Greater).solve(), IntervalSet({Interval(0., 0., IntervalKind::LR_INFINITY)}));
    assert_equal(SquareInequality(1, 1, 1, EqualityKind::NotEqual).solve(), IntervalSet({Interval(0., 0., IntervalKind::LR_INFINITY)}));

    // all points < 0
    assert_equal(SquareInequality(-1, -1, -1, EqualityKind::Equal).solve(), IntervalSet());
    assert_equal(SquareInequality(-1, -1, -1, EqualityKind::Less).solve(), IntervalSet({Interval(0., 0., IntervalKind::LR_INFINITY)}));
    assert_equal(SquareInequality(-1, -1, -1, EqualityKind::Greater).solve(), IntervalSet());
    assert_equal(SquareInequality(-1, -1, -1, EqualityKind::NotEqual).solve(), IntervalSet({Interval(0., 0., IntervalKind::LR_INFINITY)}));
    
    // 2 points == 0
    assert_equal(SquareInequality(1, -5, 4, EqualityKind::Equal).solve(), IntervalSet({Interval(1., 1.), Interval(4., 4.)}));
    assert_equal(SquareInequality(1, -5, 4, EqualityKind::Less).solve(), IntervalSet({Interval(1., 4.)}));
    assert_equal(SquareInequality(1, -5, 4, EqualityKind::Greater).solve(), IntervalSet({Interval(0., 1., IntervalKind::L_INFINITY), Interval(4., 0., IntervalKind::R_INFINITY)}));
    assert_equal(SquareInequality(1, -5, 4, EqualityKind::NotEqual).solve(), IntervalSet({Interval(0., 1., IntervalKind::L_INFINITY), Interval(1., 4.), Interval(4., 0., IntervalKind::R_INFINITY)}));

    // 1 point == 0
    assert_equal(SquareInequality(-1, 0, 0, EqualityKind::Equal).solve(), IntervalSet({Interval(0., 0.)}));
    assert_equal(SquareInequality(-1, 0, 0, EqualityKind::Less).solve(), IntervalSet({Interval(0., 0., IntervalKind::L_INFINITY), Interval(0., 0., IntervalKind::R_INFINITY)}));
    assert_equal(SquareInequality(-1, 0, 0, EqualityKind::Greater).solve(), IntervalSet());
    assert_equal(SquareInequality(-1, 0, 0, EqualityKind::NotEqual).solve(), IntervalSet({Interval(0., 0., IntervalKind::L_INFINITY), Interval(0., 0., IntervalKind::R_INFINITY)}));

    auto t = SquareInequality(1, 42, 26, EqualityKind::NotEqual);

    assert_equal(t.get_a(), 1);
    assert_equal(t.get_b(), 42);
    assert_equal(t.get_c(), 26);

    std::cout << "SUCCESS\n";
}