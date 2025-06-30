#include <stdio.h>

// Hàm tính số Fibonacci tại vị trí n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm đệ quy in Fibonacci theo thứ tự ngược lại
void printFibonacciReverse(int n) {
    if (n == 0) return;
    printf("%d", fibonacci(n - 1));
    if (n > 1) printf(", ");
    printFibonacciReverse(n - 1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        printFibonacciReverse(n);
        printf("\n");
    }

    return 0;
}
