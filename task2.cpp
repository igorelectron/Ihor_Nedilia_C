#include <iostream>
#include <vector>
#include <cmath>

int main() {
    unsigned n, d;
    std::cin >> n >> d;
    for (unsigned i = 0; i < n; i++) {
        double l = 0, q;
        for (unsigned j = 0; j < d; j++) {
            std::cin >> q;
            l += q*q;
        }
        double norm = std::sqrt(l);
        std::cout << norm << std::endl;
    } 
}