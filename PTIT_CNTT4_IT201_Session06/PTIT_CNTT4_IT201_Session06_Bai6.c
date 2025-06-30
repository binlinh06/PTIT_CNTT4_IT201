#include <stdio.h>

// Hàm đệ quy đếm số cách leo cầu thang
int countWays(int n) {
    if (n == 0 || n == 1)
        return 1; // Có 1 cách duy nhất để leo lên 0 hoặc 1 bậc
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int steps;

    printf("Nhap so bac cua cau thang: ");
    scanf("%d", &steps);

    if (steps < 0) {
        printf("Input khong hop le\n");
    } else {
        int result = countWays(steps);
        printf("%d\n", result);
    }

    return 0;
}
