// Iterative and Recursive method.
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> * prev = NULL;
    LinkedListNode<int> * curr = head;
    LinkedListNode<int> * temp;
    
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;

    

}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{   
    if(head == NULL)return head;
    LinkedListNode<int> * newHead = head;
    if(head->next!= NULL){
        newHead = reverseLinkedList(head->next);
        head->next->next = head;
    }
    
    head->next = NULL;

    return newHead;

    

}
