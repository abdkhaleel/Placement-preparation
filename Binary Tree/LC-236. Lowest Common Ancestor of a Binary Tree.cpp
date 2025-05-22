/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        if(!right) return left;
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        unordered_map<TreeNode*, TreeNode*> parent;
        st.push(root);
        parent[root] = nullptr;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(node->left){
                parent[node->left] = node;
                st.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                st.push(node->right);
            }
        }
        unordered_set<TreeNode*> ancestors;
        while(p){
            ancestors.insert(p);
            p = parent[p];
        }
        while(ancestors.find(q) == ancestors.end()){
            q = parent[q];
        }
        return q;
    }
};