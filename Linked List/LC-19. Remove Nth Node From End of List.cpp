#include "node.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int pos = size - n;
        if(n == size) return head->next;
        ListNode* prev = nullptr;
        temp = head;
        while(pos > 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        if(temp && prev) prev->next = temp->next;
        return head;
    }
};