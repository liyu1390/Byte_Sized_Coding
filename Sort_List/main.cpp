ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
        return head;
    
    auto len = lengthOfList(head);
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode *cur, *right, *left, *tail;
    for(int step = 1; step < len; step <<= 1)
    {
        cur = dummy.next;
        tail = &dummy;
        while (cur)
        {
            left = cur;
            right = splitList(left, step);
            cur = splitList(right, step);
            tail = mergeSortedAndReturnTail(left, right, tail);
        }
    }
    
    return dummy.next;
}

//split the list into 2 lists, 1 with n items and the rest. Return the head of the rest.
ListNode* splitList(ListNode* head, int n)
{
    if (head == NULL)
        return NULL;
    while(--n != 0)
    {
        head = head->next;
        if (head == NULL)
            return NULL;
    }
    ListNode* secondHead = head->next;
    head->next = NULL;
    return secondHead;
}

//merge two sorted lists, append to the tail, and return the new tail.
ListNode* mergeSortedAndReturnTail(ListNode* head1, ListNode* head2, ListNode* tail)
{
    ListNode* cur = tail;
    while(head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            cur->next = head1;
            cur = head1;
            head1 = head1->next;
        }
        else
        {
            cur->next = head2;
            cur = head2;
            head2 = head2->next;
        }
    }

    cur->next = head1 ? head1 : head2;
    while(cur->next)
    {
        cur = cur->next;
    }
    return cur;
}

int lengthOfList(ListNode* head)
{
    int counter = 0;
    while(head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}