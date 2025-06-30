#include <stdio.h>

// Hàm đệ quy để giải tháp Hà Nội
void towerOfHanoi(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("Đĩa 1 di chuyển từ %c sang %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, temp, to);                 // Chuyển n-1 đĩa sang cọc tạm
    printf("Đĩa %d di chuyển từ %c sang %c\n", n, from, to); // Di chuyển đĩa lớn nhất
    towerOfHanoi(n - 1, temp, to, from);                 // Chuyển lại n-1 đĩa sang đích
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        towerOfHanoi(n, 'A', 'C', 'B');
    }

    return 0;
}
