Node *addTwoNumbers(Node *num1, Node *num2)
{
    // The part where I fucked up here was that we have to add everything to temp and let ans stay where it is.
    Node* ans = new Node(0);
    Node * temp = ans;
    int carry = 0;
    while(num1 != NULL && num2 != NULL){
        int a = num1->data;
        int b = num2->data;
        int sum = a + b + carry;


        carry = sum/ 10;
        // I believe the assigning part had nothing to do with WA but this is how striver assigned it.
        Node * node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        num1 = num1->next;
        num2 = num2->next;
    }   
    while(num1 != NULL){
        int a = num1->data;
        
        int sum = a + carry;


        carry = sum/ 10;
        Node * node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        num1 = num1->next;
        // num2 = num2->next;
    }
    while(num2 != NULL){
        int a = num2->data;
        
        int sum = a + carry;


        carry = sum/ 10;
        Node * node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
        num2 = num2->next;
        // num2 = num2->next;
    }
    if(carry > 0){
        Node * node = new Node(carry);
        temp->next = node;
        temp = temp->next;
    }
    // 321
    // 654
    ans = ans->next;
    while(ans != NULL){
        cout << ans->data << " ";
        ans = ans -> next;
    }
}
