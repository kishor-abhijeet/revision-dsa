Node *slow = head; 
    Node *fast = head; 
    
    if(head == nullptr) 
        return {nullptr, nullptr}; 
        
    // For odd nodes, fast->next is head and 
    // for even nodes, fast->next->next is head
    while(fast->next != head && 
          fast->next->next != head) { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
