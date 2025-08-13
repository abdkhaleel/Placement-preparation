class Node{
public:
    int start, end;
    Node* left = nullptr;
    Node* right = nullptr;
    int count = 0;
    int maxCount = 0;

    Node(int s, int e): start(s), end(e){}
};
class MyCalendarTwo {
    Node* root;
    bool query(Node* node, int i, int j, int add){
        if(!node || node->start > j || node->end < i) return false;
        if(i <= node->start && node->end <= j) return node->maxCount + add >= 2;
        pushDown(node);
        add += node->count;
        return query(node->left, i, j, add) || query(node->right, i, j, add);
    }
    void pushDown(Node* node){
            int mid = (node->start + node->end) / 2;
            if(!node->left) node->left = new Node(node->start, mid);
            if(!node->right) node->right = new Node(mid+1, node->end);
        
    }
    void update(Node* node, int i, int j){
        if(node->start > j || i > node->end) return;
        if(i <= node->start && node->end <= j) {
            node->count++;
            node->maxCount++;
            return;
        }
        int mid = (node->start + node->end) / 2;
        pushDown(node);
        update(node->left, i, j);
        update(node->right, i, j);
        node->maxCount = node->count + max(node->left->maxCount, node->right->maxCount);
    }
public:
    MyCalendarTwo() {
        root = new Node(0, 1e9);
    }
    
    bool book(int startTime, int endTime) {
        if(query(root, startTime, endTime-1, 0)) return false;
        update(root, startTime, endTime-1);
        return true;
    }
};