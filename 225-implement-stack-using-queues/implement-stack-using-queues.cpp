class MyStack {
public:
    queue<int> q;
    MyStack() {
        queue<int> q;
    }
    
    void push(int x) {
        queue<int> q1;
        q1.push(x);
        while(!q.empty())
        {
            q1.push(q.front());
            cout<<q.front();
            q.pop();
        }
        swap(q,q1);
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