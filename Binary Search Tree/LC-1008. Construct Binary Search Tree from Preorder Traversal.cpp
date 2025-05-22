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
    vector<int> ngeIdx;
    void computeNGE(vector<int>& preorder){
        stack<int> st;
        int n = preorder.size();
        ngeIdx.resize(n, n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && preorder[i] > preorder[st.top()]){
                ngeIdx[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    TreeNode* builder(vector<int>& preorder, int start, int end){
        if(start > end) return nullptr;
        TreeNode* root = new TreeNode(preorder[start]);
        int nge = ngeIdx[start];
        root->left = builder(preorder, start+1, nge-1);
        root->right = builder(preorder, nge, end);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        computeNGE(preorder);
        return builder(preorder, 0, preorder.size()-1);
    }
};