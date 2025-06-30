#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm hoán đổi 2 ký tự
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp ký tự theo thứ tự a → z
void sortString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                swap(&str[i], &str[j]);
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự newline '\n' ở cuối chuỗi

    // Kiểm tra chuỗi rỗng hoặc chỉ chứa khoảng trắng
    int valid = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("Truoc khi sap xep: \"%s\"\n", str);

    sortString(str);

    printf("Sau khi sap xep: \"%s\"\n", str);

    return 0;
}
