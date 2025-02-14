#include "node.h"
#include <bits/stdc++.h>
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* temp = head;
        int c = 0;
        stack<int> st;
        while(curr){
            c++;
            st.push(curr->val);
            if(c == k){
                while(!st.empty()){
                    temp->val = st.top();
                    st.pop();
                    temp = temp->next;
                }
                c = 0;
            }
            curr = curr->next;
        }
        return head;
    }
};