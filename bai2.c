#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char action[100];
    char timestamp[30];
}Node;
typedef struct {
    int top;
    int data[];
}Struct;

void printScreen() {
printf(
    "-------------DRAW SIMULATOR--------------\n"
    "DRAW\n"
    "UNDO\n"
    "REDO\n"
    "PRINT\n"
    "EXIT\n"
    "Moi ban nhap lua chon cua ban:"
);
}

void draw{

}

int main() {
    int choice;

    do {
        printScreen();
        scanf("%d", &choice);
        switch (choice) {
            case 1:


            case 5:
                break;
                default:
                printf("\nLua chon khong hop le.\n");
                break;
        }
    }while (choice != 5);
    printf("Goodbyee");
    return 0;
}