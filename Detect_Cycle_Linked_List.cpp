bool detectCycle(Node *head)
{
	if(head == NULL)return false;
    Node * slow = head;
    Node * fast = head->next;
    while(slow != NULL && fast != NULL&& fast -> next != NULL ){ // These conditions in order are important.
        slow = slow -> next;
        fast = fast ->next->next;
        if(slow == fast)return true;
    }
    return false;

}
