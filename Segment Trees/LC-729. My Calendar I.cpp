class Node{
public:
    int start, end;
    Node* left = nullptr;
    Node* right = nullptr;
    bool cover = false;

    Node(int s, int e): start(s), end(e){}
};
class MyCalendar {
    Node* root;
    bool query(Node* node, int i, int j){
        if(!node || node->start > j || node->end < i) return false;
        if(node->cover) return true;
        if(node->start == node->end) return false;
        return query(node->left, i, j) || query(node->right, i, j);
    }
    void update(Node* node, int i, int j){
        if(node->start > j || i > node->end) return;
        if(i <= node->start && node->end <= j) {
            node->cover = true;
            node->left = node->right = nullptr;
            return;
        }
        int mid = (node->start + node->end) / 2;
        if(!node->left) node->left = new Node(node->start, mid);
        if(!node->right) node->right = new Node(mid+1, node->end);
        update(node->left, i, j);
        update(node->right, i, j);
        node->cover = node->left->cover && node->right->cover; 
    }
public:
    MyCalendar() {
        root = new Node(0, 1e9);
    }
    
    bool book(int startTime, int endTime) {
        if(query(root, startTime, endTime-1)) return false;
        update(root, startTime, endTime-1);
        return true;
    }
};