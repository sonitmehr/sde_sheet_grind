Node* removeKthNode(Node* head, int K)
{  
    // Intialise fast and slow to dummy.
    // Send fast n time front. 
    // Now gap between fast and slow is k
    // Send fast and slow to next until fast reaches last node.
    // Remember that slow reaches to one node before the one to be deleted.
    if(head == NULL)return head;
    if(head -> next == NULL)return NULL;
    Node* dummy = new Node(); // Apparently not declaring a new Node here is a game changer.
    dummy->next = head;
    Node* fast,*slow;
    fast = dummy;
    slow = dummy;

    while(K--){
        fast= fast->next;

    }

    while(fast -> next != NULL){ // Remember fast -> next comes here.
        fast = fast -> next;
        slow = slow -> next;
    }
    slow ->next = slow -> next->next;

    return dummy->next;

    
}
