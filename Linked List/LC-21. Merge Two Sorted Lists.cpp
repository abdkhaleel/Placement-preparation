#include "node.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head;
        ListNode* tail;
        if(list1->val > list2->val){
            head = tail = list2;
            list2 = list2->next;
        }
        else{
            head = tail = list1;
            list1 = list1->next;
        }
        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        tail->next = list1? list1: list2;;
        return head;
    }
};