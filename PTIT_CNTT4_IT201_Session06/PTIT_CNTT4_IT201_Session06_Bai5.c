#include <stdio.h>

// Hàm đệ quy tìm phần tử nhỏ nhất
int findMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int minRest = findMin(arr, n - 1);
    return (arr[n - 1] < minRest) ? arr[n - 1] : minRest;
}

// Hàm đệ quy tìm phần tử lớn nhất
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxRest = findMax(arr, n - 1);
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
}

int main() {
    int arr[100];
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int minVal = findMin(arr, n);
    int maxVal = findMax(arr, n);

    printf("%d, %d\n", minVal, maxVal);

    return 0;
}
