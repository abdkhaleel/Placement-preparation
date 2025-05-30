/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) { 
        const int pv = p->val, qv = q->val;
        while(true)
        {
            const int rv = root->val;
            if(pv < rv && qv < rv) root = root->left; 
            else if(pv > rv && qv > rv) root = root->right;
            else return root;
        }
    }
};