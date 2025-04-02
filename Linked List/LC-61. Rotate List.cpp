#include <node.h>
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == nullptr || head->next == nullptr) return head;
            ListNode* temp = head;
            int n = 1;
            while(temp->next != nullptr){
                n++;
                temp = temp->next;
            }
            k = k%n;
            if(k == 0) return head;
            temp->next = head;
            int pos = n - k;
            
            ListNode* tail = head;
            for(int i = 1; i < pos; i++){
                tail = tail->next;
            }
            head = tail->next;
            tail->next = nullptr;
            return head;
           
        }
    };