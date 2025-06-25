#include <stdio.h>

int linearSearch(int arr[], int size);

int main(void) {
    int arr[100];
    int size;
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

    int maxIndex = linearSearch(arr, size);
    printf("\nPhan tu lon nhat la %d tai vi tri index %d\n", arr[maxIndex], maxIndex);
    return 0;
}

int linearSearch(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}