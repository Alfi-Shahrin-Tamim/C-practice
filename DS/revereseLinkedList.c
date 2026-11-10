
struct Node* head;
void Reverse(struct Node* p){
    if( p == NULL || p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    p->next->next = p;
    p->next = NULL;
}

struct Node* Reverse(struct Node* head){
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
