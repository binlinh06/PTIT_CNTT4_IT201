#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm loại bỏ khoảng trắng và chuyển về chữ thường
void cleanString(char *src, char *dest) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isalnum(src[i])) {
            dest[j++] = tolower(src[i]);
        }
    }
    dest[j] = '\0';
}

// Hàm đệ quy kiểm tra đối xứng
int isPalindrome(const char *str, int left, int right) {
    if (left >= right) return 1;
    if (str[left] != str[right]) return 0;
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char input[200];
    char cleaned[200];

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Xóa ký tự '\n' nếu có

    cleanString(input, cleaned); // Làm sạch chuỗi: xóa khoảng trắng, ký tự đặc biệt

    if (isPalindrome(cleaned, 0, strlen(cleaned) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}
