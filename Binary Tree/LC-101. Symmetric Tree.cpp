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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> sleft;
        stack<TreeNode*> sright;
        if(root->left) sleft.push(root->left);
        if(root->right) sright.push(root->right);
        while(!sleft.empty() && !sright.empty()){
            auto node1 = sleft.top();
            auto node2 = sright.top();
            sleft.pop(), sright.pop();
            if(node1->val != node2->val) return false;
            if(node1->left || node2->right){
                if(!node1->left || !node2->right) return false;
                sleft.push(node1->left);
                sright.push(node2->right);
            }
            if(node1->right || node2->left){
                if(!node1->right || !node2->left) return false;
                sleft.push(node1->right);
                sright.push(node2->left);
            }
        }
        return sleft.empty() && sright.empty();
    }
};