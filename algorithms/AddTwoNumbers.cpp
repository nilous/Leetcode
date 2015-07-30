
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x),
          next(0) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode *it1 = l1;
    ListNode *it2 = l2;
    int carry = 0;
    
    ListNode *ret = 0;
    ListNode *it = 0;

    while (it1 || it2) {
        int sum = (it1 ? it1->val : 0) + (it2 ? it2->val : 0) + carry;
        carry = sum > 9 ? 1 : 0;
        if (!it) {
            ret = new ListNode(sum%10);
            it = ret;   
        } else {
            it->next = new ListNode(sum%10);
            it = it->next;
        }
        if (it1) it1 = it1->next;
        if (it2) it2 = it2->next;
    }
    
    if (carry)
        it->next = new ListNode(1);

    return ret;
}
