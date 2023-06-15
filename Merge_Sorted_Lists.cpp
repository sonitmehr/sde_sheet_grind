// Struggled at the while loop part. Redo it once.

Node<int>* temp,*head;
    Node<int>* l1 = first,*l2 = second;
    if(first == NULL)return second;
    if(second == NULL)return first;
    if (first->data > second->data) {
    
        head = second;
        l1 = second;
        l2 = first;
    }
    
    head = l1;
    while(l1 != NULL && l2 != NULL){
        

        while(l1 != NULL && l1->data <= l2 ->data){
            temp = l1;
            l1 = l1 -> next;
        }
        temp->next = l2;
        Node<int> * t = l1;
        l1 = l2;
        l2 = t;

    } 
    return head;
