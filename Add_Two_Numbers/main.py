def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    carryOver = 0;
    dummyHead = ListNode(0);
    cur = dummyHead;
    while (l1 != None or l2 != None):
        digitOne = l1.val if (l1 != None) else 0;
        digitTwo = l2.val if (l2 != None) else 0;
        curVal = digitOne + digitTwo + carryOver;
        carryOver = curVal / 10;
        cur.next = ListNode(curVal % 10);
        cur = cur.next;
        if (l1 != None):
            l1 = l1.next;
        if (l2 != None):
            l2 = l2.next;
    if (l1 == None and l2 == None and carryOver == 1):
        cur.next = ListNode(1);
    return dummyHead.next;