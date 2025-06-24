#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    printf("Moi ban nhap do dai cua mang");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Do dai cua mang phai lon hon 0");
        return 1;
    }

    arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("khong the tao duoc mang");
        return 1;
    }

    //Nhap gia tri vao mang
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            i--;
        }
    }

    //In
    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d \n",i+1, arr[i]);
    }
    //Giai phong bo nho
    free(arr);
    return 0;
}
