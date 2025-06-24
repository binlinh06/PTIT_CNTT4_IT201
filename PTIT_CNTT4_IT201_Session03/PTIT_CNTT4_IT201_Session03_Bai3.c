#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    printf("Moi ban nhap do dai cua mang");
    scanf("%d", &n);
    if (n < 0 || n > 1001) {
        printf("do dai mang khong hop le!!!");
        return 1;
    }
    arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Khong the tao duoc mang!!!");
        return 1;
    }

    //Nhap mang
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    //In
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    int average = 0;
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            check++;
            average += arr[i];
        }
    }
    if (check == 0) {
        printf("Khon tim thay so chan!");
        return 1;
    }else {
        float sum = (float)average / check;
        printf("Tong trung binh cac so chan la: %.2f", sum);
    }
    free(arr);
    return 0;
}