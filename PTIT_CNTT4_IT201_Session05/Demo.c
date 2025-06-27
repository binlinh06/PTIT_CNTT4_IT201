#include <stdio.h>

void print1ToN(int n);

int sum1toN(int n) {
    if (n== 1) {
        return 1;
    }
    return sum1toN(n-1) + n;
}

int main() {
    sum1toN(10);
    int sum = sum1toN(10);
    printf("sum = %d\n", sum);
    return 0;
}