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
 class Node{
public:
    int val;
    Node* next = nullptr;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
 };
class BSTIterator {
private:
    Node* head;
    Node* curr;
    void inorder(TreeNode* root, Node*& tail){
        if(!root) return;
        stack<TreeNode*> st;
        auto curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            tail->next = new Node(curr->val);
            tail = tail->next;
            curr = curr->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        inorder(root, tail);
        head = dummy->next;
        curr = head;
    }
    
    int next() {
        int ans = curr->val;
        curr = curr->next;
        return ans;
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */