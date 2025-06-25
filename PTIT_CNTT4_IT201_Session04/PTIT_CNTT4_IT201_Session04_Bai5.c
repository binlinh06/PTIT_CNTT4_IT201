#include <stdio.h>
int binarySearch(int arr[], int size, int value);
int main(void) {
    int arr[100];
    int size;
    int value;
    printf("Moi ban nhap do dai mang : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("So ban can tim la:");
    scanf("%d", &value);

    int findIndex = binarySearch(arr, size, value);
    if (findIndex !=-1) {
        printf("Phan tu co trong mang");
    }else {
        printf("Phan tu ko co trong mang\n");
    }
    return 0;
}

int binarySearch(int arr[], int size, int value) {
    int mid;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        }else if (arr[mid] < value) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return -1;
}