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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(curr != nullptr|| !st.empty()){
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            curr = node->right;
        }
        return ans;
    }
};