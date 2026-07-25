class MyQueue {
    stack<int> first,secd;
public:
    MyQueue() {
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(!first.empty()){
            secd.push(first.top());
            first.pop();
        }
        int top = secd.top();
        secd.pop();
        while(!secd.empty()){
            first.push(secd.top());
            secd.pop();
        }
        return top;
    }
    
    int peek() {
        while(!first.empty()){
            secd.push(first.top());
            first.pop();
        }
        int top = secd.top();
        while(!secd.empty()){
            first.push(secd.top());
            secd.pop();
        }
        return top;
    }
    
    bool empty() {
        return first.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */