#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    do {
        printf("Nhap so phan tu n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the tao mang!\n");
        return 1;
    }
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Gia tri lon nhat trong mang: %d\n", max);

    free(arr);

    return 0;
}
