#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t fib_n1(unsigned n) {
    uint64_t r00 = 1, r01 = 0, r10 = 0, r11 = 1; 
    uint64_t m00 = 1, m01 = 1, m10 = 1, m11 = 0; 

    unsigned i = 1;
    while (n) {
        if (n & i) {
            n ^= i;
            // r *= m
            uint64_t t00 = r00 * m00 + r01 * m10;
            uint64_t t01 = r00 * m01 + r01 * m11;
            uint64_t t10 = r10 * m00 + r11 * m10;
            uint64_t t11 = r10 * m01 + r11 * m11;
            r00 = t00;
            r01 = t01;
            r10 = t10;
            r11 = t11;
        }
        i <<= 1;

        uint64_t q00 = m00 * m00 + m01 * m10;
        uint64_t q01 = m00 * m01 + m01 * m11;
        uint64_t q10 = m10 * m00 + m11 * m10;
        uint64_t q11 = m10 * m01 + m11 * m11;
        m00 = q00;
        m01 = q01;
        m10 = q10;
        m11 = q11;
    }

    return r01;
}

uint64_t fib_n2(unsigned n) {
    if (n < 2) return n;
    uint64_t a = 0, b = 1;
    for (unsigned i = 2; i <= n; i++) {
        uint64_t t = a + b;
        a = b;
        b = t;
    }
    return b;
}


unsigned fib_less_than(uint64_t n) {
    if (n < 2) return 0;
    uint64_t a = 0, b = 1;
    unsigned i = 0;
    do {
        uint64_t t = a + b;
        a = b;
        b = t;
        i++;
    } while(b <= n);
    return i;
}


unsigned fib_greater_than(uint64_t n) {
    return fib_less_than(n + 1) + 1;
}

uint64_t sum_less_than(uint64_t n) {
    unsigned t = fib_less_than(n+1);
    uint64_t s = 0;
    for (unsigned i = 1; i <= t; i++) {
        s += fib_n2(i);
    }
    return n;
}

int main(void) {

    puts("fib1:");
    for (unsigned n = 0; n < 10; n++) {
        printf("fib[%u] = %" PRIu64 "\n", n, fib_n1(n));
    }
    puts("fib2:");
    for (unsigned n = 0; n < 10; n++) {
        printf("fib[%u] = %" PRIu64 "\n", n, fib_n2(n));
    }


    uint64_t n;
    scanf("%" SCNu64, &n);
    unsigned i = fib_less_than(n);
    printf("fib # = %u\n", i);
    printf("fib %u = %" PRIu64 "\n", i, fib_n1(i));
}