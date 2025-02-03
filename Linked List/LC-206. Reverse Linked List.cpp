#include "node.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* pointer = head;
        int n = pointer->val;
        ListNode* list = new ListNode(n);
        pointer = pointer->next;
        while(pointer){
            ListNode* temp = new ListNode(pointer->val);
            temp->next = list;
            list = temp;
            pointer = pointer->next;
        }
        return list;
    }
};