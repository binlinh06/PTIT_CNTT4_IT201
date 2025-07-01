#include <stdio.h>

// Hàm hoán đổi 2 phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (partition) cho Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // chọn phần tử chốt là phần tử cuối
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Đưa pivot vào đúng vị trí
    return i + 1;
}

// Hàm sắp xếp nhanh (Quick Sort)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm chỉ số phân hoạch
        int pi = partition(arr, low, high);

        // Gọi đệ quy tiếp tục chia mảng
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[1000], n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");

    return 0;
}
