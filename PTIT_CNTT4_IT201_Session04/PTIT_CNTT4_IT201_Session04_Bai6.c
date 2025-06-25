#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int findStudentById(Student student[], int size, int searchId);

int main() {
    Student students[MAX];
    int searchId;

    printf("Nhap thong tin cho %d sinh vien:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        students[i].id = i + 1;
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("id: %d\n", students[i].id);

        printf("name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        while (1) {
            printf("age: ");
            if (scanf("%d", &students[i].age) == 1 && students[i].age >= 0) {
                while (getchar() != '\n'); // Xóa ký tự thừa sau scanf
                break;
            }
            printf("Tuoi khong hop le. Vui long nhap lai!\n");
            while (getchar() != '\n'); // Xóa dòng bị lỗi
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
        if (student[i].id == searchId) return i;
    }
    return -1;
}
