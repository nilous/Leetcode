#ifndef LIST_INC
#define LIST_INC

#include <iostream>
#include <initializer_list>

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

std::ostream &operator<<(std::ostream &os, ListNode *list) {
    auto *it = list;
    while (it != nullptr) {
        os << it->val << ',';
        it = it->next;
    }
    os << '\n';
    return os;
}

ListNode *BuildList(std::initializer_list<int> &il) {
    ListNode *head, *prev; 
    head = prev = nullptr;

    for (auto i : il) {
        ListNode *node = new ListNode(i);
        if (prev == nullptr) head = node;
        else prev->next = node;
        prev = node;
    } 

    return head;
}

#endif
