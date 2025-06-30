#include <stdio.h>

// Hàm đệ quy in nhị phân
void printBinary(int n) {
    if (n == 0)
        return;

    printBinary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int n;

    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        printf("Dang nhi phan: ");
        printBinary(n);
        printf("\n");
    }

    return 0;
}
