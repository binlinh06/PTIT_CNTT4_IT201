#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    int *arr;

    do {
        printf("Nhap so phan tu (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the tao mang!\n";
        return 1;
    }

    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so can dem: ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }

    printf("So lan xuat hien cua %d la: %d\n", x, count);

    free(arr);

    return 0;
}
