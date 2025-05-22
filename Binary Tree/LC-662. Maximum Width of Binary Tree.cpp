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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        long res = 1;
        q.push({root, 0});

        while(!q.empty()){
            long minIdx = q.front().second;
            int size = q.size();
            long first, last;
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                int idx = q.front().second - minIdx;
                q.pop();
                if(i == 0) first = idx;
                if(i == size-1) last = idx;
                if(node->left != nullptr){
                    q.push({node->left, (long) idx*2 + 1});
                }
                if(node->right != nullptr){
                    q.push({node->right, (long) idx*2 + 2});
                }
            }
            res = max(res, last - first + 1);
        }
        return res;
    }
};