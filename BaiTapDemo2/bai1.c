#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;

typedef struct SingleNode {
    Task *task;
    struct SingleNode *next;
}SingleNode;
typedef struct DoubleNode {
    Task *task;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
SingleNode *createNode(Task *task) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    node->task = task;
    node->next = NULL;
    return node;
}
void addTask(SingleNode **head,Task *task) {
    SingleNode *newNode = createNode(task);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    SingleNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displayTask(SingleNode *head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("DANH SACH QUAN LY NHIEM VU\n");
    while (head != NULL) {
        printf("id:%d\n",head->task->id);
        printf("Title:%s\n",head->task->title);
        printf("Priority:%d\n",head->task->priority);
        printf("Deadline:%s\n",head->task->deadline);
        printf("\n");
        head = head->next;
    }
}
void deleteTask(SingleNode **head,int id) {
    SingleNode *temp = *head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->task->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Ko tim thay task can xoa!\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    }else {
        prev->next = temp->next;
    }
    free(temp->task);
    free(temp);
    printf("Xoa thanh cong!\n");
}
void updateTask(SingleNode *head,int id) {
    while (head != NULL) {
        if (head->task->id == id) {
            getchar();
            printf("Moi ban nhap ten moi:");
            fgets(head->task->title,sizeof(head->task->title),stdin);
            head->task->title[strcspn(head->task->title,"\n")] = '\0';
            printf("Moi ban nhap muc do uu tien:");
            scanf("%d",&head->task->priority);
            getchar();
            printf("Moi ban nhap thoi gian hoan thanh:");
            fgets(head->task->deadline,sizeof(head->task->deadline),stdin);
            head->task->deadline[strcspn(head->task->deadline,"\n")] = '\0';
            printf("Cap nhap thanh cong!\n");
            return;
        }
        head = head->next;
    }
    printf("Ko tim thay Task\n");
}
void addToComplete(DoubleNode **head,Task *task) {
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->task = task;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL) {
        *head = newNode;
    }else {
        DoubleNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void markComplete(SingleNode **head,DoubleNode **completedHead,int id) {
    SingleNode *temp = *head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->task->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Ko tim thay task can xoa!\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    }else {
        prev->next = temp->next;
    }
    addToComplete(completedHead,temp->task);
    free(temp);
    printf("Cap nhap thanh cong!\n");
}
void sortTasksByPriority(SingleNode *head) {
    if (head == NULL) return;
    SingleNode *i,*j;
    for (i=head;i->next != NULL;i=i->next) {
        for (j=i;j->next != NULL;j=j->next) {
            if (i->task->priority > j->task->priority) {
                Task *temp = i->task;
                i->task = j->task;
                j->task = temp;

            }
        }
    }
    printf("Sap xep thanh cong theo muc do uu tien tang dan!\n");
}
void searchTasksByTitle(SingleNode *head,const char *keyword) {
    int found = 0;
    while (head != NULL) {
        if (strstr(head->task->title, keyword) != NULL) {
            printf("id:%d\n",head->task->id);
            printf("Title:%s\n",head->task->title);
            printf("Priority:%d\n",head->task->priority);
            printf("Deadline:%s\n",head->task->deadline);
            printf("\n");
            found = 1;
        }
        head = head->next;
    }
    if (!found) {
        printf("Khong tim thay nhiem vu phu hop!\n");
    }
}
int main(void) {
    int choice,id;
    int count = 1;
    SingleNode *head = NULL;
    DoubleNode *completedHead = NULL;
    do {
        printf("==========MENU==========\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhap nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim kiem nhiem vu\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                Task *newTask = (Task *)malloc(sizeof(Task));
                newTask->id = count++;
                getchar();
                printf("Moi ban nhap nhiem vu:");
                fgets(newTask->title,sizeof(newTask->title),stdin);
                newTask->title[strcspn(newTask->title,"\n")] = '\0';
                printf("Moi ban nhap muc do uu tien:");
                scanf("%d",&newTask->priority);
                getchar();
                printf("Moi ban nhap thoi gian hoan thanh:");
                fgets(newTask->deadline,sizeof(newTask->deadline),stdin);
                newTask->deadline[strcspn(newTask->deadline,"\n")] = '\0';
                addTask(&head,newTask);
                break;
            case 2:
                displayTask(head);
                break;
            case 3:
                printf("Moi ban nhap id con xoa:");
                scanf("%d",&id);
                deleteTask(&head,id);
                break;
            case 4:
                printf("Moi ban nhap id can nhap nhat:");
                scanf("%d",&id);
                updateTask(head,id);
                break;
            case 5:
                printf("Moi ban nhap id can hoan thanh:");
                scanf("%d",&id);
                markComplete(&head,&completedHead,id);
                break;
            case 6:
                sortTasksByPriority(head);
                break;
            case 7:
                getchar(); // Xoá '\n' sau scanf
                char keyword[100];
                printf("Nhap tu khoa can tim: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = '\0';
                searchTasksByTitle(head, keyword);
                break;
            case 8:
                printf("Thoat thanh cong!");
                break;
            default:
                printf("ERROR");
        }
    }while (choice != 8);
    return 0;
}