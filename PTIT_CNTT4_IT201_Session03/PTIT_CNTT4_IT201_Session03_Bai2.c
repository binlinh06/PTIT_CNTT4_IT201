#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("Moi ban nhap do dai cua mang");
    scanf("%d",&n);
    if (n<=0) {
        printf("Do dai cua mang phai lon hon 0");
        return 1;
    }
    arr =(int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Khong the tao duoc mang");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d \n",i+1,arr[i]);
    }
    int Max = arr[0];
    for (int i = 0 ; i < n; i++) {
        if (arr[i] > Max) {
            Max = arr[i];
        }
    }
    printf("Max = %d",Max);
    free(arr);
    return 0;
}

