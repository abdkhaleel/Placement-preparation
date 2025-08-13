class Node{
public:
    int start, end;
    Node* left = nullptr;
    Node* right = nullptr;
    int count = 0;
    int maxCount = 0;

    Node(int s, int e): start(s), end(e){}
};
class MyCalendarThree {
    Node* root;
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
    MyCalendarThree() {
        root = new Node(0, 1e9);
    }
    
    int book(int startTime, int endTime) {
        update(root, startTime, endTime-1);
        return root->maxCount;
    }
};