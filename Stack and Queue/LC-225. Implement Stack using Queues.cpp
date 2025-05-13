class MyStack {
    public:
        deque<int> dq;
        MyStack() {
            
        }
        
        void push(int x) {
            dq.push_front(x);
        }
        
        int pop() {
            int x = dq.front();
            dq.pop_front();
            return x;
        }
        
        int top() {
            return dq.front();
        }
        
        bool empty() {
            return dq.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */