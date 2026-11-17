

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

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode->data = x;
    newNode->next = newNode;
    return newNode;
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
