struct Node {
    int data;
    struct Node* next;
};

struct Node* GetNewNode(int x);
void         AddToBegin(int x, struct Node** tail);
void         AddToEnd(int x, struct Node** tail);
void         PrintList(struct Node** tail);
int          FindIndex(int val, struct Node** tail);
int          ListSize(struct Node** tail);
void         DeleteFromBegin(struct Node** tail);
void         DeleteFromEnd(struct Node** tail);
void         FreeList(struct Node** tail);
void         Rotate(struct Node** tail, int forward);
void         ReplaceAtPos(struct Node** tail, int pos, int val);
void         DeleteByValue(struct Node** tail, int val);
void         DeleteAtPos(struct Node** tail, int pos);
void         Reverse(struct Node** tail);

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode->data = x;
    newNode->next = newNode;
    return newNode;
}

void Reverse(struct Node** tail){
    if(*tail == NULL || *tail == (*tail)->next) return;
    struct Node* head = (*tail)->next;
    struct Node* prev = *tail;
    struct Node* current = head;
    do{
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while ( prev != *tail);
    *tail = head;
}

void Rotate(struct Node** tail, int forward){
    if(*tail == NULL) return;
    int size = ListSize(tail);
    int rotations = forward % size;
    if(rotations < 0) rotations = size + rotations;
    for(int i = 0; i < rotations; i++) *tail = (*tail)->next;
}

void AddToBegin(int x, struct Node** tail){
    struct Node* temp2 = GetNewNode(x);
    if(temp2 == NULL) return;
    if(*tail == NULL) {
        *tail = temp2;
        return;
    }
    temp2->next = (*tail)->next;
    (*tail)->next = temp2;
}
void AddToEnd(int x, struct Node** tail){
    struct Node* temp = GetNewNode(x);
    if(temp == NULL) return;
    if(*tail == NULL){
        *tail = temp;
        return;
    }
    temp->next = (*tail)->next;
    (*tail)->next = temp;
    *tail = temp;
}

void ReplaceAtPos(struct Node** tail, int pos, int val){
    if(*tail == NULL || pos < 1 || pos > ListSize(tail)) return;
    struct Node* temp = *tail;
    for(int i = 0; i < pos; i++) temp = temp->next;
    temp->data = val;
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

void DeleteByValue(struct Node** tail, int val){
    if(*tail == NULL) return;
    if(*tail == (*tail)->next){
        if((*tail)->data == val) {
            free(*tail);
            *tail = NULL;
        }
        return;
    }
    struct Node* temp1 = *tail;
    while(temp1->next != *tail) {
        if(temp1->next->data == val){
            struct Node* temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
            return;
        }
        temp1 = temp1->next;
    }
    if ((*tail)->data == val){
        temp1->next = (*tail)->next;
        struct Node* temp2 = *tail;
        *tail = temp1;
        free(temp2);
    }
}

void DeleteAtPos(struct Node** tail, int pos){
    if(*tail == NULL || pos < 1) return;
    if((*tail)->next == *tail){
        if(pos == 1){
            free(*tail);
            *tail = NULL;
        }
        return;
    }
    int size = ListSize(tail);
    if(pos > size) return;    
    struct Node* del = *tail;
    struct Node* temp = *tail;
    for(int i = 0; i < pos; i++) del = del->next;
    while(temp->next != del) temp = temp->next;
    temp->next = del->next;
    if(del == *tail) *tail = temp;
    free(del);
}


int FindIndex(int val, struct Node** tail){
    if(*tail == NULL) return -1;
    struct Node* temp = (*tail)->next;
    if(temp->data == val) return 1;
    int i = 1;
    while(1){
        temp = temp->next; i++;
        if(temp->data == val) return i;
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
