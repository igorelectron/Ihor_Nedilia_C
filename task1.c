#include <stdio.h>


int main(void) {
    int nums[5] = { 0, 42, 26, 1426, 426 };
    double num;
    scanf("%lf", &num);

    int count = 0;
    for (int i = 0; i < 5; i++) {
        count += nums[i] > num;
    }
    printf("%d", count);
}