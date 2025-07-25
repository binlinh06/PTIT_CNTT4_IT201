#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char action; // 'I' = Insert
    char value;  // Ký tự được thao tác
} Operation;

typedef struct {
    Operation data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Operation op) {
    if (!isFull(s)) {
        s->data[++(s->top)] = op;
    }
}

Operation pop(Stack *s) {
    Operation nullOp = {' ', ' '};
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return nullOp;
}

void printMenu() {
    printf("\n====== TRINH SOAN THAO VAN BAN ======\n");
    printf("1. INSERT\n");
    printf("2. UNDO\n");
    printf("3. REDO\n");
    printf("4. HIEN THI\n");
    printf("5. THOAT\n");
    printf("Chon chuc nang (1-5): ");
}

int main() {
    char text[MAX] = "";
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    int choice;
    char x;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // INSERT
                printf("Nhap ky tu muon chen: ");
                scanf(" %c", &x);
                {
                    int len = strlen(text);
                    text[len] = x;
                    text[len + 1] = '\0';

                    Operation op = {'I', x};
                    push(&undoStack, op);

                    // Reset redo stack sau khi insert
                    initStack(&redoStack);
                }
                break;

            case 2: // UNDO
                if (!isEmpty(&undoStack)) {
                    Operation lastOp = pop(&undoStack);
                    if (lastOp.action == 'I') {
                        int len = strlen(text);
                        if (len > 0) {
                            text[len - 1] = '\0'; // xóa ký tự cuối
                            push(&redoStack, lastOp);
                        }
                    }
                } else {
                    printf("Khong co thao tac de UNDO!\n");
                }
                break;

            case 3: // REDO
                if (!isEmpty(&redoStack)) {
                    Operation redoOp = pop(&redoStack);
                    if (redoOp.action == 'I') {
                        int len = strlen(text);
                        text[len] = redoOp.value;
                        text[len + 1] = '\0';
                        push(&undoStack, redoOp);
                    }
                } else {
                    printf("Khong co thao tac de REDO!\n");
                }
                break;

            case 4: // HIỂN THỊ
                printf("Van ban hien tai: %s\n", text);
                break;

            case 5: // THOÁT
                printf("Dang thoat chuong trinh...\n");
                exit(0);

            default:
                printf("Lua chon khong hop le. Vui long chon tu 1-5.\n");
                break;
        }
    }

    return 0;
}
