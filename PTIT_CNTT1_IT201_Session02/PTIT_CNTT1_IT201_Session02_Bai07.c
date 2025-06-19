#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, target;
    int *arr;
    int found = 0;

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

    printf("Nhap tong can tim: ");
    scanf("%d", &target);

    for (int i = 0; i < n - 1 && !found; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("%d,%d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Khong tim thay\n");
    }

    free(arr);

    return 0;
}
