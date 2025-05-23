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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        auto curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(find(root, k-curr->val, curr)) return true;
            curr = curr->right;

        }
        return false;
    }

    bool find(TreeNode* root, int val, TreeNode* curr){
        while(root){
            if(val > root->val) root = root->right;
            else if(val == root->val && root != curr) return true;
            else root = root->left;
        }
        return false;
    }
};