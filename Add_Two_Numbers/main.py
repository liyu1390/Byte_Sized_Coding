def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    carryOver = 0;
    dummyHead = ListNode(0);
    cur = dummyHead;
    while (l1.next != None or l2.next != None):
        digitOne = (l1.next != None) ? l1.val : 0;
        digitTwo = (l2.next != None) ? l2.val : 0;
        curVal = digitOne + digitTwo + carryOver;
        carryOver = curVal / 10;
        cur.next = ListNode(curVal % 10);
        cur = cur.next;
        if (l1.next != None) l1 = l1.next;
        if (l2.next != None) l2 = l2.next;
    return dummyHead.next;