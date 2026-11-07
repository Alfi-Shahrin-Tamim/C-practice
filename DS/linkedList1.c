#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Insert(struct Node** pointerHead, int x){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->next = *pointerHead;
    temp->data = x;
    *pointerHead = temp;
}

void Print(struct Node* head){
    printf("List: ");
    while(head != NULL){
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){

    struct Node* head = NULL;
    printf("How many numbers: ");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n ; i++){
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
}

