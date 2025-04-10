#include "List.h"
class Solution {
  public:
    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        
        Node* res;
        if(a->data < b->data){
            res = a;
            res->bottom = merge(a->bottom, b);
        }else{
            res = b;
            res->bottom = merge(a, b->bottom);
        }
        return res;
    }
    Node* flatten(Node *root) {
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next);
        
        root = merge(root, root->next);
        
        return root;
        
        
    }
};