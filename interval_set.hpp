#ifndef _INTERVAL_SET_HPP_
#define _INTERVAL_SET_HPP_

#include <vector>

#include "interval.hpp"

class IntervalSet {
public:
    IntervalSet() = default;
    IntervalSet(std::vector<Interval> vec) : intervals(vec) {}

    // reat from stdin with hint on stdout
    static IntervalSet input_with_hint(); 

    double length() const {
        double l = 0.;
        for (size_t i = 0; i < intervals.size(); i++) {
            l += intervals[i].length();
        }
        return l;
    }

    size_t size() const {
        return intervals.size();
    }

    std::vector<Interval>& get_intervals() {
        return intervals;
    }
    const std::vector<Interval>& get_intervals() const {
        return intervals;
    }
protected:
    std::vector<Interval> intervals;
};

// io
std::ostream& operator<<(std::ostream& out, const IntervalSet& interval);
std::istream& operator>>(std::istream& in, IntervalSet& interval);

// interval union
IntervalSet operator+(const Interval& a, const Interval& b);
// interval difference
IntervalSet operator-(const Interval& a, const Interval& b);

// intersection
IntervalSet operator*(const IntervalSet& a, const IntervalSet& b);
// union
IntervalSet operator+(const IntervalSet& a, const IntervalSet& b);
// difference
IntervalSet operator-(const IntervalSet& a, const IntervalSet& b);

#endif//_INTERVAL_SET_HPP_