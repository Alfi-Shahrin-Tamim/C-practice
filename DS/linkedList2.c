#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* GetNewNode(int x){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void InsertAtPos(struct Node** head, int pos, int val){
    if(pos < 1) return;
    if(*head == NULL){
        struct Node* temp = GetNewNode(val);
        *head = temp;
        return;
    }
    if(pos == 1){
        struct Node* temp1 = *head;
        struct Node* temp2 = GetNewNode(val);
        *head = temp2;
        temp2->next = temp1;
        return;
    }
    struct Node* temp1 = *head;
    for(int i = 1; i < pos - 1 && temp1->next != NULL; i++) temp1 = temp1->next;
    struct Node* temp2 = GetNewNode(val);
    if(temp1->next != NULL) temp2->next = temp1->next;
    temp1->next = temp2;
}

void DeleteAtPos(struct Node** head, int pos){
    if(*head == NULL || pos < 1) return;
    if(pos == 1){
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* temp1 = *head;
    int i;
    for(i = 1; i < pos - 1 && temp1->next != NULL; i++) temp1 = temp1->next;
    struct Node* temp2 = temp1->next;
    if(i < pos - 1 || temp1->next == NULL) return;
    if(temp2->next != NULL) temp1->next = temp2->next;
    else temp1->next = NULL;
    free(temp2);
}
void Print(){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}

int main(){

    head = NULL;
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print();

}

