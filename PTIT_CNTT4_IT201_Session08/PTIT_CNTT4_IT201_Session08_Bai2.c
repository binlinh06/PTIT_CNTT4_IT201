#include <stdio.h>

// Hàm tìm kiếm nhị phân (đã cải thiện)
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Tránh overflow

        if (arr[mid] == key)
            return mid; // Trả về vị trí (bắt đầu từ 0)
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
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

    // Nhập mảng đã được sắp xếp
    printf("Nhap cac phan tu da duoc sap xep tang dan:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Kiểm tra mảng có thực sự được sắp xếp không
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Canh bao: Mang chua duoc sap xep dung!\n");
            break;
        }
    }

    // Nhập giá trị cần tìm
    printf("Nhap gia tri can tim: ");
    scanf("%d", &key);

    // Gọi hàm tìm kiếm
    int pos = binarySearch(arr, n, key);

    // Xuất kết quả
    if (pos != -1) {
        printf("Phan tu vi tri thu %d\n", pos + 1); // vị trí tính từ 1
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}