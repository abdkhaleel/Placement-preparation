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
    int maxBSTSum;
    tuple<int, int, int>  maxSum(TreeNode* root){
        if(!root) return {0, INT_MAX, INT_MIN};

        auto [lsum, lmin, lmax] = maxSum(root->left);
        auto [rsum, rmin, rmax] = maxSum(root->right);

        if(root->val > lmax && root->val < rmin){
            int currSum = lsum + rsum + root->val;
            maxBSTSum = max(maxBSTSum, currSum);
            return{currSum, min(root->val, lmin), max(root->val, rmax)};
        }

        return {max(lsum, rsum), INT_MIN, INT_MAX};

    }
public:
    int maxSumBST(TreeNode* root) {
        maxBSTSum = 0;
        maxSum(root);
        return maxBSTSum;
    }
};