/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val, {});
        stack<Node*> st;
        st.push(node);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            for(auto adj: curr->neighbors){
                if(mp.find(adj) == mp.end()){
                    mp[adj] = new Node(adj->val, {});
                    st.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};