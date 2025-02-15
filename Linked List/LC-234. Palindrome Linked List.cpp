#include "node.h"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        while(slow){
            if(slow->val != st.top()) return false;
            slow = slow->next;
            st.pop();
        }
        return true;
    }
};