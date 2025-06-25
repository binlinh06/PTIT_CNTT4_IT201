#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[100];
    int n;
    bool found = false;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Nhập mảng
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Tìm và in các cặp đối xứng
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - 1 - i]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - 1 - i]);
            found = true;
        }
    }

    if (!found) {
        printf("Khong co phan tu doi xung\n");
    }

    return 0;
}
