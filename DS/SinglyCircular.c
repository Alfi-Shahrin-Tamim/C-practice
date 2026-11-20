
struct Node {
    int data;
    struct Node* next;
};

struct Node* GetNewNode(int x);
struct Node* AddToBegin(int x, struct Node** tail);
struct Node* AddToEnd(int x, struct Node** tail);
void         PrintList(struct Node** tail);
int          FindIndex(int x, struct Node** tail);
int          ListSize(struct Node** tail);
void         DeleteFromBegin(struct Node** tail);
void         DeleteFromEnd(struct Node** tail);
void         FreeList(struct Node** tail);
void         Rotate(struct Node** tail, int forward);

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode->data = x;
    newNode->next = newNode;
    return newNode;
}

void Rotate(struct Node** tail, int forward){
    if(*tail == NULL) return;
    int size = ListSize(tail);
    int rotations = forward % size;
    if(rotations < 0) rotations = size + rotations;
    for(int i = 0; i < rotations; i++) *tail = (*tail)->next;
}

struct Node* AddToBegin(int x, struct Node** tail){
    struct Node* temp2 = GetNewNode(x);
    if(temp2 == NULL) return NULL;
    if(*tail == NULL) {
        *tail = temp2;
        return temp2;
    }
    temp2->next = (*tail)->next;
    (*tail)->next = temp2;
    return temp2;
}
struct Node* AddToEnd(int x, struct Node** tail){
    struct Node* temp2 = GetNewNode(x);
    if(temp2 == NULL) return NULL;
    if(*tail == NULL){
        *tail = temp2;
        return temp2;
    }
    temp2->next = (*tail)->next;
    (*tail)->next = temp2;
    *tail = temp2;
    return temp2;
}

void DeleteFromBegin(struct Node** tail){
    if(*tail == NULL) return;
    struct Node* temp = (*tail)->next;
    if(temp == (*tail)) {
        (*tail) = NULL;
        free(temp);
        return;
    }
    (*tail)->next = (*tail)->next->next;
    free(temp);
    return;
}

void DeleteFromEnd(struct Node** tail){
    if(*tail == NULL) return;
    struct Node* temp = (*tail)->next;
    if(temp == (*tail)) {
        (*tail) = NULL;
        free(temp);
        return;
    }    
    while(temp->next != (*tail)) temp = temp->next;
    struct Node* temp2 = (*tail);
    *tail = temp;
    temp->next = temp2->next;
    free(temp2);
    return;
}
int FindIndex(int x, struct Node** tail){
    if(*tail == NULL) return -1;
    struct Node* temp = (*tail)->next;
    if(temp->data == x) return 1;
    int i = 1;
    while(1){
        temp = temp->next; i++;
        if(temp->data == x) return i;
        if(temp == (*tail)->next) return -1;
    }
}

int ListSize(struct Node** tail){
    if(*tail == NULL) return 0;
    int i = 1;
    struct Node* temp = (*tail)->next;
    if(temp == *tail) return 1;
    while(1){
        temp = temp->next;
        i++;
        if(temp == *tail) return i;
    }
}

void FreeList(struct Node** tail){
    if(*tail == NULL) return;
    struct Node* temp1 = (*tail)->next;
    if(temp1 == *tail) {
        free(temp1);
        *tail = NULL;
        return;
    }
    while(temp1 != *tail){
        struct Node* temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    free(*tail);
    *tail = NULL;
}

void PrintList(struct Node** tail){
    if(*tail == NULL) return;
    if((*tail)->next == *tail) {
        printf("Element: %d\n", (*tail)->data);
        return;
    }
    struct Node* temp = (*tail)->next;
    printf("Elements:");
    while(1) {
        printf(" %d", temp->data); 
        temp = temp->next;
        if(temp == (*tail)->next) break;
    }
    printf("\n");

}
