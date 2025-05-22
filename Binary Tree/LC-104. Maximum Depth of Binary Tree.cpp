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
private:
    int maxWidth = 1;
    void dfs(TreeNode* node, int width){
        if(node->left) dfs(node->left, width + 1);
        if(node->right) dfs(node->right, width + 1);
        maxWidth = max(maxWidth, width);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return maxWidth;
    }
};