#include <stdio.h>
#include <stdlib.h>

int main() {
    int cols,rows;

    printf("Moi ban nhap rows :");
    scanf("%d",&rows);
    printf("Moi ban nhap cols :");
    scanf("%d",&cols);

    if (rows <= 0 || cols <= 0) {
        printf("so phan tu khong hop le!!!");
        return 1;
    }
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0 ; j < cols; j++) {
            printf("arr[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0 ; j < cols; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int Max = arr[0][0];
    int Min = arr[0][0];
    for (int i = 0; i < cols; i++) {
        for (int j = 0 ; j < rows; j++) {
            if (arr[i][j] > Max) {
                Max = arr[i][j];
            }
            if (arr[i][j] < Min) {
                Min = arr[i][j];
            }
        }
    }
    printf("Max = %d \n",Max);
    printf("Min = %d",Min);

    return 0;
}
