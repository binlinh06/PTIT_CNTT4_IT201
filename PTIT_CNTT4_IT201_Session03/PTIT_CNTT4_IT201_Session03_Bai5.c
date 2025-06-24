#include <stdio.h>

int main() {
    int rows,cols;
    printf("Moi ban nhap rows : ");
    scanf("%d",&rows);
    printf("Moi ban nhap cols : ");
    scanf("%d",&cols);
    if (rows <=0 || rows > 1001 || cols <= 0 || cols > 1001) {
    printf("Do dai mang khong hop le!");
        return 1;
    }else if (rows != cols){
        printf("So hang so cot khong hop le!");
        return 1;
    }

    int arr[rows][cols];
    //Nhap gia tri vao mang
    for (int i =0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    //In
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ",arr[i][j]);
        }
        printf("\n");
    }

    //Tong duong cheo chinh
    int sumRows = 0;
    for (int i = 0; i < rows; i++) {
        sumRows += arr[i][i];
    }
    printf("Tong duong cheo chinh = %d",sumRows);

    //Tong duong cheo phu
    printf("\n");
    int sumCols = 0;
    for (int i = 0; i < cols; i++) {
        sumCols += arr[i][cols - 1 - i];
    }
    printf("Tong duong cheo phu = %d",sumCols);
    return 0;
}