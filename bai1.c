#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char type[100];
    int duration;
    int calories;
    char date[100];
} Activities;

typedef struct Node {
    Activities data;
    struct Node *next;
} Node;

void freeActivities(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void printScreen() {
    printf(
    "\n--------Health Tracker----------\n"
    "1. Them hoat dong trong ngay\n"
    "2. Hien thi danh sach hoat dong\n"
    "3. Xoa hoat dong\n"
    "4. Cap nhat thong tin hoat dong\n"
    "5. Thong ke calories tieu thu/ngay\n"
    "6. Sap xep hoat dong\n"
    "7. Tim kiem hoat dong\n"
    "8. Thoat chuong trinh\n"
    "Moi ban nhap lua chon cua ban: ");
}

Activities input() {
    Activities data;
    printf("Moi ban nhap ID hoat dong: ");
    scanf("%d", &data.id);
    printf("Moi ban nhap loai hoat dong: ");
    getchar();
    fgets(data.type, 100, stdin);
    data.type[strcspn(data.type, "\n")] = 0;
    printf("Moi ban nhap thoi gian thuc hien hoat dong (phut): ");
    scanf("%d", &data.duration);
    printf("Moi ban nhap luong calories da tieu thu: ");
    scanf("%d", &data.calories);
    printf("Moi ban nhap ngay thuc hien hoat dong: ");
    getchar();
    fgets(data.date, 100, stdin);
    data.date[strcspn(data.date, "\n")] = 0;
    return data;
}

void addActivities(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = input();
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printActivities(Node* head) {
    if (head == NULL) {
        printf("\nDanh sach rong. Khong co gi de hien thi.\n");
        return;
    }
    printf("\n--- DANH SACH HOAT DONG ---\n");
    while (head != NULL) {
        printf("ID: %d | Loai: %s | Thoi gian: %d phut | Calories: %d | Ngay: %s\n",head->data.id, head->data.type, head->data.duration,head->data.calories, head->data.date);
        head = head->next;
    }
}

void deleteActivities(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    if (*head == NULL) {
        printf("There is no activities that could be deleted\n");
        return;
    }
    int delID;
    printf("Moi ban nhap id can xoa");
    scanf("%d", &delID);
    if (current->data.id == delID) {
        *head = current->next;
        free(current);
        return;
    }
    while (current->data.id != delID || current->next != NULL) {
            previous = current;
            current = current->next;
            if (current->next == NULL && current->data.id != delID) {
                printf("Khong tim thay id de xoa");
                return;
            }
        }

        previous->next = current->next;
        free(previous);
    return;
    }

void updateActivity(Node** head) {
    Node* current = *head;
    if (*head == NULL) {
        printf("There is no activities that could be deleted\n");
        return;
    }
    int updateID;
    printf("Moi ban nhap id can xoa");
    scanf("%d", &updateID);
    if (current->data.id == updateID) {
        *head = current->next;
        free(current);
        return;
    }
    while (current->data.id != updateID && current->next != NULL) {
        current = current->next;
        if (current->next == NULL && current->data.id != updateID) {
            printf("Khong tim thay id de update");
            return;
        }
    }


    if (current == NULL) {
        printf(" Khong tim thay hoat dong\n");
        return;
    }

    printf("Nhap ten hoat dong moi: ");
    getchar();
    fgets(current->data.type, 100, stdin);
    current->data.type[strcspn(current->data.type, "\n")] = 0;
    printf("Nhap thoi luong moi: ");
    scanf("%d", &current->data.duration);
    printf("Nhap calories moi: ");
    scanf("%d", &current->data.calories);
    printf("Cap nhat thanh cong \n");
}


void searchActivities(Node* head) {
    Node* current = head;
    char searchType[100];
    printf("Moi ban nhap type can tim kiem");
    getchar();
    fgets(searchType, 100, stdin);
    searchType[strcspn(searchType,"\n")] = 0;
    if (strcmp(*head->data.type,searchType) == 0) {
        printf("Thong tin:ID: %d | Loai: %s | Thoi gian: %d phut | Calories: %d | Ngay: %s\n",head->data.id, head->data.type, head->data.duration,head->data.calories, head->data.date);
    }else {
        while (strcmp(current->data.type,searchType) != 0 || current->next != NULL) {
            current = current->next;
            if(current->next != NULL && strcmp(current->data.type,searchType) != 0) {
                printf("Khong tim thay type!");
                return;
            }
        }
        printf("Thong tin: ID: %d | Loai: %s | Thoi gian: %d phut | Calories: %d | Ngay: %s\n",current->data.id, current->data.type, current->data.duration,current->data.calories, current->data.date);
            return;
    }
}

int main() {
    int choice;
    Node* ActivitiesList = NULL;

    do {
        printScreen();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Them Hoat Dong Moi ---\n");
                addActivities(&ActivitiesList);
                break;
            case 2:
                printActivities(ActivitiesList);
                break;
            case 3:
                deleteActivities(&ActivitiesList);
                break;
            case 6:
                updateActivity(&ActivitiesList);
                break;
            case 7:
                searchActivities(ActivitiesList);
                break;
            case 8:
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);

    printf("\nTam biet!\n");
    freeActivities(&ActivitiesList);

    return 0;
}
