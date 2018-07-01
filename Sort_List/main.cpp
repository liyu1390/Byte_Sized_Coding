ListNode* sortList(ListNode* head) {
    auto secondHead = splitAndReturnSecondHalf(head, lengthOfList(head));
    if (secondHead == NULL)
    {
        return head;
    }
    return mergeTwoSortedList(sortList(head), sortList(secondHead));
}

ListNode* mergeTwoSortedList(ListNode* head1, ListNode* head2)
{
    if (head2 == NULL)
        return head1;
    ListNode tempRoot(0);
    ListNode* slider = &tempRoot;
    while(head1 != NULL && head2 != NULL)
    {
        if (head1->val <= head2->val)
        {
            slider->next = head1;
            slider = head1;
            head1 = head1->next;
        }
        else
        {
            slider->next = head2;
            slider = head2;
            head2 = head2->next;
        }
    }
    if (head2 == NULL)
    {
        slider->next = head1;
    }
    else if (head1 == NULL)
    {
        slider->next = head2;
    }
    return tempRoot.next;
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

ListNode* splitAndReturnSecondHalf(ListNode* head, int lengthOfList)
{
    if (lengthOfList <= 1)
        return NULL;
    for (int i = 0; i < std::ceil(lengthOfList/2.0) - 1; i++)
    {
        head = head->next;
    }
    ListNode* secondHead = head->next;
    head->next = NULL;
    return secondHead;
}