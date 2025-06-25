#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int findStudentById(Student student[], int size, int searchId);

int main(void) {
    Student students[MAX];
    int searchId;

    printf("Nhap thong tin cho %d sinh vien:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        students[i].id = i + 1; // Gán id bắt đầu từ 1
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("id: %d\n", students[i].id);
        while (getchar() != '\n'); // Xóa tất cả ký tự còn sót lại trong stdin cho tới khi gặp '\n'

        printf("name: ");
        getchar(); // Xóa ký tự Enter còn lại
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Xóa dấu xuống dòng

        char ageStr[10];
        int age;
        while (1) {
            printf("age: ");
            fgets(ageStr, sizeof(ageStr), stdin);
            if (sscanf(ageStr, "%d", &age) == 1 && age >= 0) {
                students[i].age = age;
                break;
            } else {
                printf("Tuoi khong hop le. Vui long nhap lai!\n");
            }
        }
    }

    printf("\nNhap id can tim: ");
    scanf("%d", &searchId);

    int index = findStudentById(students, MAX, searchId);
    if (index != -1) {
        printf("\nThong tin sinh vien:\n");
        printf("id: %d\n", students[index].id);
        printf("name: %s\n", students[index].name);
        printf("age: %d\n", students[index].age);
    } else {
        printf("Khong tim thay sinh vien co ID %d\n", searchId);
    }

    return 0;
}

int findStudentById(Student student[], int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (student[i].id == searchId) {
            return i;
        }
    }
    return -1;
}
