struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* GetNewNode(int x);
int   find(int x, struct Node** headPtr);
void  ReplaceAtPos(int n, int x, struct Node** headPtr);
void  InsertAtPos(int n, int x, struct Node** headPtr);
void  InsertAtHead(int x, struct Node** headPtr);
void  InsertAtTail(int x, struct Node** headPtr);
void  DeleteByValue(int x, struct Node** headPtr);
void  DeleteAtPos(int n, struct Node** headPtr);
void  PrintList(struct Node** headPtr);
void  ReversePrintList(struct Node** headPtr);
void  ReverseList(struct Node** headPtr);
void  FreeList(struct Node** headPtr);
int   ListSize(struct Node** headPtr);

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void ReverseList(struct Node** headPtr){
    if(*headPtr == NULL) return;
    struct Node* temp1 = *headPtr;
    while(temp1->next != NULL) temp1 = temp1->next;
    *headPtr = temp1;
    while(temp1 != NULL){
        struct Node* temp2 = temp1->prev;
        temp1->prev = temp1->next;
        temp1->next = temp2;
        temp1 = temp2;
    }
}

int find(int x, struct Node** headPtr){
    if(*headPtr == NULL)  return -1;
    struct Node* temp1 = *headPtr;  
    for(int i = 1; temp1 != NULL; i++){
        if(temp1->data == x) return i;
        temp1 = temp1->next;
    } 
    return -1; 
}

void ReplaceAtPos(int n, int x, struct Node** headPtr){
    if(n < 1 || *headPtr == NULL) return;
    struct Node* temp1 = *headPtr;
    for(int i = 0; i < n - 1 && temp1 != NULL; i++) temp1= temp1->next;
    if(temp1 == NULL) {
        printf("Replacement failed.\n");
        return;
    }
    temp1->data = x;
}

void InsertAtPos(int n, int x, struct Node** headPtr){
    if(n < 1) return;
    if (n == 1) {
        InsertAtHead(x, headPtr);
        return;
    }
    struct Node* temp1 = *headPtr;
    for(int i = 0; i < n - 2 && temp1 != NULL; i++) temp1 = temp1->next;
    if(temp1 == NULL) return;
    if(temp1->next != NULL){
        struct Node* newNode = GetNewNode(x);
        struct Node* temp2 = temp1->next;
        temp2->prev = newNode;
        temp1->next = newNode;
        newNode->prev = temp1;
        newNode->next = temp2;
    }
    else InsertAtTail(x, headPtr);
}


void InsertAtHead(int x, struct Node** headPtr){
    struct Node* newNode = GetNewNode(x);
    if(*headPtr == NULL){
       *headPtr = newNode;
        return;
    }
    (*headPtr)->prev = newNode;
    newNode->next = *headPtr;
    *headPtr = newNode;
}

void InsertAtTail(int x, struct Node** headPtr){
    struct Node* newNode = GetNewNode(x);
    if(*headPtr == NULL){
        *headPtr = newNode;
        return;
    }
    struct Node* temp = *headPtr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DeleteByValue(int x, struct Node** headPtr){
    if(*headPtr == NULL) return;
    if((*headPtr)->data == x) {
        DeleteAtPos(1, headPtr);
        return;
    }
    struct Node* temp1 = (*headPtr)->next;
    while( temp1 != NULL) {
        if(temp1->data == x){
            temp1->prev->next = temp1->next;
            if(temp1->next != NULL) temp1->next->prev = temp1->prev;
            free(temp1);
            return;
        }
        temp1 = temp1->next;
    }
}

void DeleteAtPos(int n, struct Node** headPtr){
    if(*headPtr == NULL || n < 1) return;
    struct Node* temp1 = *headPtr;
    if(n == 1){
        *headPtr= temp1->next;
        if(*headPtr != NULL) (*headPtr)->prev = NULL;
        free(temp1);
        return;
    }

    for(int i = 0; i < n - 2 && temp1 != NULL ; i++) temp1 = temp1->next;
    if(temp1 == NULL || temp1->next == NULL) return;
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    if( temp1->next != NULL) temp1->next->prev = temp1;
    free(temp2);
}

void PrintList(struct Node** headPtr){
    struct Node* temp = *headPtr;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrintList(struct Node** headPtr){

    struct Node* temp = *headPtr;
    if(temp == NULL) return;
    while( temp-> next != NULL){
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void FreeList(struct Node** headPtr){
    if(*headPtr == NULL) return;
    struct Node* temp1 = *headPtr;
    while(temp1 != NULL) {
        struct Node* temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    *headPtr = NULL;
}
int ListSize(struct Node** headPtr){
    if(*headPtr == NULL) return 0;
    struct Node* temp = *headPtr;
    int n = 0;
    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    return n;
}
