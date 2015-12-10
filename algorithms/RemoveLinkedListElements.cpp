/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "helpers/List.hpp"

// 当然也可以老老实实地写啦，但这个二级指针的写法是不是很炫技？很屌曝？
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto it = &head;
        while (*it) {
            if ((*it)->val == val) DeleteNode(it);
            else it = &(*it)->next;
        }
        return head;
    }

    // 删除一个节点
    // 可以处理tail节点
    void DeleteNode(ListNode **node) {
        if (!(*node)->next) *node = nullptr;
        else std::swap(**node, *(*node)->next);
        // delete
    }
};

int main(int ac, char **av) {
    auto l = BuildList(std::initializer_list<int>{1,2,6,3,4,5,6});

    auto r = Solution().removeElements(l, 6);
    std::cout << r;
    
    /*
    for (auto i = &l; (*i) != nullptr; ) {
        Solution().DeleteNode(i); 
        std::cout << l;
    }
    */
    return 0;
}
