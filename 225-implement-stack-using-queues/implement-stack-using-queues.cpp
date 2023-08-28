class MyStack {
public:
    queue<int> q;
    MyStack() {
        queue<int> q;
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++)
        {
            q.push(top());
            q.pop();
        }
    }
    
    int pop() {
        int res = top();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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