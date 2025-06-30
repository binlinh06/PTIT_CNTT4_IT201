#include <stdio.h>

// Hàm đệ quy tính tổng các chữ số
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;

    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        int result = sumOfDigits(n);
        printf("%d\n", result);
    }

    return 0;
}
