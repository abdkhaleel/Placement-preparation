class LRUCache {
private:
    class Node{
        public:
            Node* prev;
            Node* next;
            int key;
            int val;
            Node(int key, int val){
                this->key = key;
                this->val = val;
                prev = NULL;
                next = NULL;
            }
    };
public:
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void Insert(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void Delete(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        Delete(node);
        Insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Delete(mp[key]);
            mp.erase(key);
            Node* node = new Node(key, value);
            mp[key] = node;
            Insert(node);
        }
        else{
            if(mp.size() == capacity){
                Node* node = tail->prev;
                mp.erase(node->key);
                Delete(node);
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            Insert(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */