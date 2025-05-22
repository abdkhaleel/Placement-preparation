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
    int postorder_index;
    TreeNode* build(vector<int>& postorder, int start, int end){
        if(start > end) return nullptr;

        int rootVal = postorder[postorder_index--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
    
        root->right = build(postorder, mid+1, end);
        root->left = build(postorder, start, mid-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();
        postorder_index = postorder.size()-1;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return build(postorder, 0, inorder.size()-1);
        
    }
};