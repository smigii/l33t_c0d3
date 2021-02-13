//
// Created by neo on 2021-02-12.
//

#ifndef L33T_SWAPSECONDLINKEDLIST_HPP
#define L33T_SWAPSECONDLINKEDLIST_HPP

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head){
    std::cout << head->val << " ";
    ListNode* n = head->next;
    if(n != nullptr)
        printList(head->next);
    else
        std::cout << "\n";
}

ListNode* makeList(int n, int i){
    if(n <= i){
        ListNode* newNode = new ListNode(n);
        newNode->next = makeList(++n, i);
        return newNode;
    } else {
        return nullptr;
    }
}
ListNode* makeList(int n){
    return makeList(1, n);
}

void shredList(ListNode* node){
    if(node->next){
        shredList(node->next);
    }
    delete(node);
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        } else {
            ListNode* temp = head->next;
            head->next = swapPairs(head->next->next);
            temp->next = head;
            return temp;
        }
    }
};

void SwapSecondLinkedList(){

    std::cout << "=== Swap Every Second Element in Linked List\n";

    ListNode* first = makeList(9);

    printList(first);

    Solution s = Solution();
    first = s.swapPairs(first);

    printList(first);

    shredList(first);

    std::cout << "=== END SSLL\n";
}

#endif //L33T_SWAPSECONDLINKEDLIST_HPP
