#include <stdio.h>

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Trả về vị trí (tính từ 0)
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    int arr[1000];
    int n, key;

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nhập các phần tử
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Nhập giá trị cần tìm
    printf("Nhap gia tri can tim: ");
    scanf("%d", &key);

    // Gọi hàm tìm kiếm
    int pos = linearSearch(arr, n, key);

    // Xuất kết quả
    if (pos != -1) {
        printf("Vi tri thu %d\n", pos + 1); // Đếm từ 1 cho người dùng
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}
