#include "node.h"
#include <bits/stdc++.h>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        while(headA || headB){
            if(headA){
                if(set.find(headA) != set.end()) return headA;
                set.insert(headA);
                headA = headA->next;
            }
            if(headB){
                if(set.find(headB) != set.end()) return headB;
                set.insert(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};