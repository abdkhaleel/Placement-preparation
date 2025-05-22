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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*, long long, long long>> st;
        st.push({root, LLONG_MAX, LLONG_MIN});
        while(!st.empty()){
            auto [node, upper, lower] = st.top();
            st.pop();

            if(!node) continue;
            if(node->val >= upper || node->val <= lower) return false;
            st.push({node->left, node->val, lower});
            st.push({node->right, upper, node->val});
        }
        return true;
    }
};