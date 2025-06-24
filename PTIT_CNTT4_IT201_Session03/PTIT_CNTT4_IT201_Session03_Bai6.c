#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    int *arr;

    printf("Moi ban nhap do dai cua mang n:");
    scanf("%d", &n);
    if ( n <= 0 ) {
        printf("Số lượng phần tử không hợp lệ");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    //Cap nhap mang them
    printf("Moi ban nhap so luong phan tu muon them m: ");
    scanf("%d", &m);

    if (m > 0) {
        // Cấp phát lại mảng với kích thước mới (n + m)
        int *temp = realloc(arr, (n + m) * sizeof(int));
        if (temp == NULL) {
            printf("Khong du bo nho\n");
            free(arr);
            return 1;
        }
        arr = temp;

        // Nhập thêm m phần tử
        printf("Nhap %d phan tu muon them:\n", m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr[n + i]);
        }
        n += m; // Cập nhật lại độ dài mảng
    }
        for (int i = 0; i < n; i++) {
            printf("%d, ", arr[i]);
        }
    return 0;
}