/**
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

#include "helpers/List.hpp"

// TODO: 这个解法并不高明，显然中间有一些改变next的动作是无意义的（这些节点本就在同一List中）
//       一段一段处理似乎会更好一些。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        auto *it = head;
        auto it1 = l1;
        auto it2 = l2;

        while (it1 != nullptr && it2 != nullptr) {
            ListNode *&i = (it1->val <= it2->val) ? it1 : it2;
            if (!head) {  // 当然也可以将head的问题现在循环之前解决掉
                it = head = i;
            } else {
                it->next = i;
                it = it->next;
            }
            i = i->next;
        }
/*
        // TODO: 这里看起来就很累赘，应该可以写得漂亮些
        if (it1 != nullptr) {
            if (it) it->next = it1;
            else head = it1;
        }
        if (it2 != nullptr) {
            if (it) it->next = it2;
            else head = it2;
        }
*/
        auto rest = (it1 != nullptr) ? it1 : (it2 != nullptr) ? it2 : nullptr;
        ListNode *&tail = head ? it->next : head;
        tail = rest;
        
        return head;
    }
};

int main(int ac, char **av) {
    auto l1 = BuildList(std::initializer_list<int>{1,2,4,8});
    auto l2 = BuildList(std::initializer_list<int>{3,5,7,9});
    auto r = Solution().mergeTwoLists(l1, l2);
    std::cout << r;
    

    return 0;
}
