#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, newValue;
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

    printf("Nhap vi tri muon sua (0 den %d): ", n - 1);
    scanf("%d", &pos);
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }

    arr[pos] = newValue;

    printf("Mang sau khi cap nhat:\n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\n");

    free(arr);

    return 0;
}
