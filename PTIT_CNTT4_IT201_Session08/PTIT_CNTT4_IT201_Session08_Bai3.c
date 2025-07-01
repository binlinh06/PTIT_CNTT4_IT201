#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Cờ kiểm tra có hoán đổi hay không
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi 2 phần tử
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if (swapped == 0) break;
    }
}

int main() {
    int n, arr[1000];

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    // Nhập các phần tử
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Gọi hàm sắp xếp
    bubbleSort(arr, n);

    // In kết quả sau khi sắp xếp
    printf("Mang sau khi sap xep:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");

    return 0;
}
