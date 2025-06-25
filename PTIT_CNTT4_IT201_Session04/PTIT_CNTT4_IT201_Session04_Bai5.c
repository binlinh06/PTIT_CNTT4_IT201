#include <stdio.h>

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int size, int value);

// Hàm sắp xếp mảng tăng dần (bubble sort đơn giản)
void sortArray(int arr[], int size);

int main(void) {
    int arr[100];
    int size;
    int value;

    printf("Moi ban nhap do dai mang: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng trước khi tìm kiếm
    sortArray(arr, size);

    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSo ban can tim la: ");
    scanf("%d", &value);

    int findIndex = binarySearch(arr, size, value);
    if (findIndex != -1) {
        printf("Phan tu co trong mang tai vi tri %d\n", findIndex);
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    return 0;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
