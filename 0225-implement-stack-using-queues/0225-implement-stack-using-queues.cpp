class MyStack {
    queue<int> first, secd;
public:
    MyStack() {}
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        if(first.size() == 0) return -1;
        while(first.size() > 1){
            secd.push(first.front());
            first.pop();
        }
        int front = first.front();
        first.pop();
        swap(first, secd);
        return front;
    }
    
    int top() {
        if(first.size() == 0) return -1;
        while(first.size() > 1){
            secd.push(first.front());
            first.pop();
        }
        int front = first.front();
        secd.push(first.front());
        first.pop();
        swap(first, secd);
        return front;
    }
    
    bool empty() {
        return first.empty();
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