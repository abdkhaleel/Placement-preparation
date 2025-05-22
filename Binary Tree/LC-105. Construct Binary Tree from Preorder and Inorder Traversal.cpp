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
    unordered_map<int, int> mp;
    int preorder_index;
    TreeNode* build(vector<int>& preorder, int start, int end){
        if(start > end) return nullptr;

        int rootVal = preorder[preorder_index++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->left = build(preorder, start, mid-1);
        root->right = build(preorder, mid+1, end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        preorder_index = 0;
        return build(preorder, 0, inorder.size()-1);
        
    }
};