typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* temp = malloc(sizeof(MyLinkedList));
    if(temp == NULL) return NULL;
    temp->next = NULL;
    return temp;    
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj == NULL || index < 0) return -1;
    MyLinkedList* temp = obj;
    for(int i = 0; i <= index && temp != NULL; i++) temp = temp->next;
    if(temp == NULL) return -1;
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj == NULL) return;
    MyLinkedList* temp = myLinkedListCreate();
    if(temp == NULL) return;
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(obj == NULL) return;
    MyLinkedList* temp1 = myLinkedListCreate();
    if(temp1 == NULL) return;
    temp1->val = val;
    MyLinkedList* temp2 = obj;
    while(temp2->next != NULL) temp2 = temp2->next;
    temp2->next = temp1;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj == NULL || index < 0) return;
    if(obj->next == NULL){
        if(index > 0) return;
        else{
            MyLinkedList* temp = myLinkedListCreate();
            if(temp == NULL) return;
            temp->val = val;
            obj->next = temp;
            return;
        }
    }
    MyLinkedList* temp2 = obj;
    int i;
    for(i = 0; i < index && temp2->next != NULL; i++) temp2 = temp2->next;
    if(i < index  || temp2 == NULL) return;
    MyLinkedList* temp1 = myLinkedListCreate();
    if(temp1 == NULL) return;
    temp1->val = val;    
    if(temp2->next != NULL) temp1->next = temp2->next;
    temp2->next = temp1;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(obj == NULL || obj->next == NULL || index < 0) return;
    MyLinkedList* temp1 = obj;
    int i;
    for(i = 0; i < index && temp1 != NULL; i++) temp1 = temp1->next;
    if(i < index || temp1 == NULL || temp1->next == NULL) return;
    MyLinkedList* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void myLinkedListFree(MyLinkedList* obj) {
    if(obj == NULL ) return;
    if(obj->next == NULL){
        free(obj);
        obj = NULL;
        return;
    }
    MyLinkedList* temp1 = obj;
    while(temp1 != NULL){
        MyLinkedList* temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }
    obj = NULL;
}
