#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Moi ban nhap rows: ");
    scanf("%d", &rows);
    printf("Moi ban nhap cols: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows > 1000) {
        printf("So hang khong hop le\n");
        return 1;
    }
    if (cols <= 0 || cols > 1000) {
        printf("So cot khong hop le\n");
        return 1;
    }

    // Cấp phát bộ nhớ động cho mảng 1 chiều mô phỏng mảng 2 chiều
    int *arr = (int *)malloc(rows * cols * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    // Nhập giá trị
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i * cols + j]);
        }
    }

    // In mảng
    printf("\nMang vua nhap:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", arr[i * cols + j]);
        }
        printf("\n");
    }

    // Tính tổng 1 hàng
    int k;
    printf("Nhap so hang can tinh tong (1-%d): ", rows);
    scanf("%d", &k);
    if (k < 1 || k > rows) {
        printf("Hang khong hop le\n");
    } else {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[(k - 1) * cols + j];
        }
        printf("Tong hang %d = %d\n", k, sum);
    }

    free(arr); // Giải phóng bộ nhớ
    return 0;
}
