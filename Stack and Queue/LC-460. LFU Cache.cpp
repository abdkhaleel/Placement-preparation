class Node{
    public:
        Node* next;
        Node* prev;
        int key, value, frequency;
        Node(int k, int v): key(k), value(v), next(NULL), prev(NULL), frequency(1){}
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;

        DoublyLinkedList(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        void add(Node* node){
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
        }

        void remove(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        Node* pop(){
            Node* node = tail->prev;
            remove(node);
            return node;
        }
};

class LFUCache {
public:
    int capacity, min_freq;
    unordered_map<int, Node*> key_map;
    unordered_map<int, DoublyLinkedList*> freq_map;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }
    
    int get(int key) {
        if(key_map.find(key) == key_map.end()) return -1;
        Node* node = key_map[key];
        updateFrequency(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(key_map.find(key) != key_map.end()){
            Node* node = key_map[key];
            node->value = value;
            updateFrequency(node);
        }
        else{
            if(key_map.size() == capacity){
                removeLRU();
            }
            Node* node = new Node(key, value);
            key_map[key] = node;
            min_freq = 1;
            if(freq_map.find(min_freq) == freq_map.end()){
                freq_map[min_freq] = new DoublyLinkedList();
            }
            freq_map[min_freq]->add(node);
        }
    }

    void updateFrequency(Node* node){
        int old_frequency = node->frequency;
        node->frequency++;
        freq_map[old_frequency]->remove(node);
        if(old_frequency == min_freq &&
            freq_map[old_frequency]->head->next == freq_map[old_frequency]->tail){
                min_freq++;
            }
        if(freq_map.find(node->frequency) == freq_map.end()){
            freq_map[node->frequency] = new DoublyLinkedList();
        }
        freq_map[node->frequency]->add(node);
    }

    void removeLRU(){
        if(freq_map.find(min_freq) != freq_map.end()){
            Node* node = freq_map[min_freq]->pop();
            key_map.erase(node->key);
            delete node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */