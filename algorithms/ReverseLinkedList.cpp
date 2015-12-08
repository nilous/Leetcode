#include "helpers\List.hpp"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;

        auto *it = head;
        auto *next = head->next;
        head->next = nullptr;  // 别忘了这个

        while (next != nullptr) {
            auto tmp = next->next;
            next->next = it;
            it = next;
            next = tmp;
        }

        return it;
    }
};

int main(int ac, char **av) {
    auto l = BuildList(std::initializer_list<int>{});
    auto rl = Solution().reverseList(l);
    std::cout << rl;
    return 0;
}
