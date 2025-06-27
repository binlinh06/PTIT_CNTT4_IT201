#include <stdio.h>

void printFrom1ToN(int n);

int main() {
    int n;
    printf("Nhap 1 so nguyen duong: ");
    scanf("%d", &n);

    if (n<=0) {
        printf("So phai la so nguyen duong!\n");
        return 1;
    }
    printf("Cac so tu 1 den %d:\n",n);
    printFrom1ToN(n);
    return 0;
}

void printFrom1ToN(int n) {
    if (n==0) return;
    printFrom1ToN(n-1);
    printf("%d\n", n);
}