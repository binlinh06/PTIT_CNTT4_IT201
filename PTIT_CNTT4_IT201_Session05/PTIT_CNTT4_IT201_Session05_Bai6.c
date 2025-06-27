#include <stdio.h>

// Hàm đệ quy tính tổng mảng
int sumArray(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int arr[100];
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int total = sumArray(arr, n);
    printf("Tong mang: %d\n", total);

    return 0;
}
