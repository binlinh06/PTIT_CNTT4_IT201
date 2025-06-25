#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[100];
    int n, value;
    bool found = false;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Nhập mảng
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Nhập giá trị cần tìm
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    // Tìm và in các vị trí
    printf("Vi tri cua cac phan tu co gia tri %d: ", value);
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("%d ", i);
            found = true;
        }
    }

    if (!found) {
        printf("\nPhan tu khong co trong mang\n");
    } else {
        printf("\n");
    }

    return 0;
}
