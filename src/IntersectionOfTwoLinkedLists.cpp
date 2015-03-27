
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x = 0)  // We don't care about the data
        : val(x),
          next(0) {}
};

size_t sizeOfList(ListNode *head) {
    if (!head)
        return 0;
    int count = 1;
    while (head->next) {
        count++;
        head = head->next;
    }
    return count;
}

ListNode *moveForward(ListNode *list, size_t steps) {
    ListNode *r = list;
    for (size_t i = 0; i < steps; i++) {
        // if (r == 0) assert(0);
        r = r->next;
    }
    return r;
}

// Constraints:
//   Time complexity: O(n)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    // O(m+n)
    size_t sizeA = sizeOfList(headA);
    size_t sizeB = sizeOfList(headB);

    // O(abs(m-n))
    if (sizeA > sizeB)
        a = moveForward(a, sizeA-sizeB);
    else if (sizeA < sizeB)
        b = moveForward(b, sizeB-sizeA);

    // O(min(m,n))
    while (a != 0) {
        if (a == b)
            return a;
        a = moveForward(a, 1);
        b = moveForward(b, 1);
    }

    // Total: O(3n)
    return 0;
}