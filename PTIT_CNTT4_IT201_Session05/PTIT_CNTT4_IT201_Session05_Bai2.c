#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isPositiveInteger(char str[]) {
    if (str[0] == '\0') return 0; // chuỗi rỗng
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int sumRecursive(int n) {
    if (n<=1) return 0;
    return n+sumRecursive(n-1);
}

int main() {
    char input[100];
    printf("Nhap mot chuoi: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Xóa ký tự '\n' nếu có

    if (isPositiveInteger(input)) {
        int n = atoi(input);
        int result = sumRecursive(n);
        printf("%d\n", result);
    } else {
        printf("Khong hop le\n");
    }

    return 0;
}