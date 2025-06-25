#include <stdio.h>

int linearSearch(int arr[], int size, int value );
int binarySearch(int arr[], int size, int value);

int main(void) {
        int numbers[10] = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9};
        int findIndex = linearSearch(numbers, 10, 0);
        if (findIndex !=-1) {
                printf("Found at index %d\n", findIndex);
        }else {
                printf("Not found\n");
        }
        return 0;
}

int linearSearch(int arr[], int size, int value) {
        for (int i =0; i < size; i++) {
                if (arr[i] == value) {
                        return i;
                }
        }
        return -1;
}

int binarySearch(int arr[], int size, int value) {
        int mid;
        int low = 0;
        int high = size - 1;
        while (low <= high) {
                mid = (low + high) / 2;
                //So sanh gia tri can tim kiem voi phan tu o giua
                if (arr[mid] == value) {
                        return mid;
                }else if (value < arr[mid]) {
                        //Neu nho hon thi tiep tuc tim o phan ben trai
                        high = mid - 1;
                }else {
                        //Neu lon hon thi tiep tuc tim kiem o ben phai
                        low = mid + 1;
                }
        }
        return -1;
}