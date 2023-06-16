Node *firstNode(Node *head)


{
   // Remember why fast and slow point meet in cycle.
  // Wait for intersection of fast and slow.
  // Then start nexting from head and intersection point to meet at the cycle beginning point.
  // Remember why this works.
  // Slow -> L1 + L2
  // Fast -> L1 + L2 + n*C
  // Fast = 2* SLow
  // L1 + L2 = nC
  // L1 = nC - L2 [ Main reason ]
    if(head == NULL || head -> next == NULL)return NULL;   
    Node * slow = head,*fast = head,*start=  head; // Don't assign head->next to fast.
    int flag = 0;
    while(fast != NULL && fast->next != NULL){ // Check fast -> next here
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            while(start != slow){
                start = start->next;
                slow = slow->next;
            }
            return start;
        }
    }
    return NULL;

    
    
}
