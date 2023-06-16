// Simple logic.
// Go till end of list then set next of end to start.
// Now traverse next for len - k  nodes from end.

Node *rotate(Node *head, int k) {
     int len = 1; // This has to be 1 god dammit.
     if(head == NULL || head->next==NULL || k == 0)return head;
     Node* temp = head;
     while(temp -> next != NULL){
          len++;
          temp = temp -> next;
     }
     k = k % len; // Standard modulo stuff.
     int val = len - k;
     
     temp -> next = head;
     while(val--){
          temp = temp -> next;
     }
     // cout << temp->data << " ";
     head = temp -> next;// = head;
      temp -> next = NULL;
      return head;
}
