#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    do {
        printf("Nhap so phan tu (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the tao mang!\n");
        return 1;
    }

    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Cac phan tu lon hon cac phan tu ben phai:\n");

    int maxRight = arr[n - 1];
    printf("%d", maxRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            printf(",%d", arr[i]);
            maxRight = arr[i];
        }
    }

    printf("\n");

    free(arr);

    return 0;
}
