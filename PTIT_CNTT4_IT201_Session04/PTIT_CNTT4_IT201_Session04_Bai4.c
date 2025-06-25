#include <stdio.h>

int linearSearch(int arr[], int size , int key);

int main(void) {
    int arr[100];
    int size;
    int key;
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
    scanf("%d", &key);
    int findIndex = linearSearch(arr, size,key);
    if (findIndex !=-1) {
        printf("Found at index %d\n", findIndex);
    }else {
        printf("Không tìm thấy phần tử\n");
    }


    return 0;
}

int linearSearch(int arr[], int size, int key) {
    int counter = -1;
    for (int i =0; i < size; i++) {
        if (arr[i] == key) {
            counter = i;
        }
    }
    return counter;
}