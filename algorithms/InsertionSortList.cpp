/* Sort a linked list using insertion sort. */

#include "helpers/List.hpp"

class Solution {
public:
    // 此解法很慢(虽然没有TLE)
    // 应该是内层循环并不是“从后向前”遍历导致的
    //
    // 但是实际上“从前向后”和“从后向前”没有本质区别，考虑下面两种情况：
    // 1, 99, 2, 3, ..., 98
    // 1, 99, 98, 97 ..., 2
    // 在后面的情况下，本解法应该是有性能优势的。
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return nullptr;

        for (auto prev = head, it = head->next; it != nullptr; prev = it, it = it->next) {
            if (prev->val <= it->val) continue;

            ListNode *prev2 = nullptr;
            ListNode *it2 = head;
            for (; it2 != it && it->val > it2->val; prev2 = it2, it2 = it2->next) ;

            prev->next = it->next;
            if (!prev2) {
                it->next = head;
                head = it;
            } else {
                prev2->next = it;
                it->next = it2;
            }
        }

        return head;
    }
};



int main(int ac, char **av) {
    auto l = BuildList(std::initializer_list<int>{4,3,2,1});
    std::cout << l;
    auto l2 = Solution().insertionSortList(l);
    std::cout << l2;
    return 0;
}
