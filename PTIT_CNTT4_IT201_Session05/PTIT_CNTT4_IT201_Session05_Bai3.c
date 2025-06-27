#include <stdio.h>

// Hàm tính giai thừa dùng đệ quy
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Khong hop le\n");
    } else {
        unsigned long long result = factorial(n);
        printf("%llu\n", result);
    }

    return 0;
}
