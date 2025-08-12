struct Node{
    int start, end;
    bool cover = false;
    int lazy = -1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int s, int e) : start(s), end(e) {}
};
class RangeModule {
    Node* root;
    void apply(Node* node, int val){
        node->cover = (val == 1);
        node->lazy = val;
    }
    void passdown(Node* node){
        if(node->start == node->end) return;
        int mid = (node->start + node->end) / 2;
        if(!node->left) node->left = new Node(node->start, mid);
        if(!node->right) node->right = new Node(mid+1, node->end);
        if(node->lazy != -1){
            apply(node->left, node->lazy);
            apply(node->right, node->lazy);
            node->lazy = -1;
        }
    }
    void update(Node* node, int l, int r, int val){
        if(!node || l > node->end || r < node->start) return;
        if(l <= node->start && node->end <= r){
            apply(node, val);
            return;
        }
        passdown(node);
        update(node->left, l, r, val);
        update(node->right, l, r, val);
        node->cover = getCover(node->left) && getCover(node->right);
    }
    bool query(Node* node, int l, int r){
        if(!node || r < node->start || l > node->end) return true;
        if(l <= node->start && node->end <= r) return node->cover;
        passdown(node);
        return query(node->left, l, r) && query(node->right, l, r);
    }
    bool getCover(Node* node){
        return node? node->cover: false;
    }
public:
    RangeModule() {
        root = new Node(1, 1e9);
    }
    
    void addRange(int left, int right) {
        update(root, left, right-1, 1);
    }
    
    bool queryRange(int left, int right) {
        return query(root, left, right-1);
    }
    
    void removeRange(int left, int right) {
        update(root, left, right-1, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */