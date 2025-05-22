/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p || !q) return 0;
        stack<TreeNode*> st1;
        st1.push(p);
        stack<TreeNode*> st2;
        st2.push(q);
        while(!st1.empty() && !st2.empty()){
            auto node1 = st1.top();
            st1.pop();
            auto node2 = st2.top();
            st2.pop();
            if(node1 && node2){
                if(node1->val != node2->val) return false;
                if(node1->left || node2->left) {
                    if(!node1->left || !node2->left) return false;
                    st1.push(node1->left);
                    st2.push(node2->left);
                }
                if(node1->right || node2->right) {
                    if(!node1->right || !node2->right) return false;
                    st1.push(node1->right);
                    st2.push(node2->right);
                }
            }
        }
        return st1.empty() && st2.empty();
    }
};