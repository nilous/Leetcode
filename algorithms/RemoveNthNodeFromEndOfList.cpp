/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include "helpers/List.hpp"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode* head, int n) {
        auto n_prev = head;
        auto it = head;
        
        int i = 0;
        while (it->next != nullptr) {
            it = it->next;
            ++i;
            if (i > n)
                n_prev = n_prev->next;
        }

        if (n_prev != head || i == n) {  // i==n时，n_prev=head，且确实是找到了n_prev而非因为n_prev是初始值
            auto tmp = n_prev->next;
            n_prev->next = tmp->next;
        } else {
            head = head->next;
        }
        // TODO: 应该delete，但不知道是new还是malloc来的

        return head;
    }
};

int main(int ac, char **av) {
    auto head = BuildList(std::initializer_list<int>{1});  // XXX: 为何不能自动转换
    auto l = Solution().removeNthFromEnd(head, 1);
    //std::cout << head; 
    std::cout << l;
    return 0;
}
