#include <stdio.h>

// Hàm đệ quy tính tổng từ firstNum đến secondNum
int sumRecursive(int first, int second) {
    if (first > second)
        return 0;
    return first + sumRecursive(first + 1, second);
}

int main() {
    int firstNum, secondNum;

    printf("Nhap hai so nguyen duong (firstNum secondNum): ");
    scanf("%d %d", &firstNum, &secondNum);

    if (firstNum < 0 || secondNum < 0 || firstNum > secondNum) {
        printf("Khong hop le\n");
    } else {
        int result = sumRecursive(firstNum, secondNum);
        printf("%d\n", result);
    }

    return 0;
}
