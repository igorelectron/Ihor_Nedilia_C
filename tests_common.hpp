#ifndef _TESTS_COMMON_
#define _TESTS_COMMON_

#include <cmath>
#include <cstdlib>
#include <iostream>

#include <square_inequality.hpp>

// test helper functions

bool is_approx_equal(double a, double b) {
    // a == b needed for inf to inf cmp
    return a == b || std::abs(a - b) < 1e-9;
}

bool is_approx_equal(const Interval& a, const Interval& b) {
    return a.get_kind() == b.get_kind() && is_approx_equal(a.get_l(), b.get_l()) && is_approx_equal(a.get_r(), b.get_r());
}

bool is_approx_equal(const IntervalSet& a, const IntervalSet& b) {
    if (a.size() != b.size()) return false;

    // check that intervals coinside
    auto& ai = a.get_intervals();
    auto& bi = b.get_intervals();

    // a contains in b
    for (auto& av : ai) {
        bool found = false;
        for (auto& bv : bi) {
            if (is_approx_equal(av, bv)) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    // b contains in a
    for (auto& bv : bi) {
        bool found = false;
        for (auto& av : ai) {
            if (is_approx_equal(av, bv)) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}


void assert_equal(double a, double b) {
    if (!is_approx_equal(a, b)) {
        std::cout << a << " != " << b << "\n";
        std::cout << "TEST FAILED\n"; 
        std::exit(EXIT_FAILURE);
    }
}

void assert_equal(const Interval& a, const Interval& b) {
    if (!is_approx_equal(a, b)) {
        std::cout << a << " != " << b << "\n";
        std::cout << "TEST FAILED\n"; 
        std::exit(EXIT_FAILURE);
    }
}

void assert_equal(const IntervalSet& a, const IntervalSet& b) {
    if (!is_approx_equal(a, b)) {
        std::cout << a << " != " << b << "\n";
        std::cout << "TEST FAILED\n"; 
        std::exit(EXIT_FAILURE);
    }
}

#endif//_TESTS_COMMON_