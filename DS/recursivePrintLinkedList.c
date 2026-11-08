void Print(struct Node* head){
    if(head == NULL) return;
    Print(head->next);
    printf("%d", head->data);
}
