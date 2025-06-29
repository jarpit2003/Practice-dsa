class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
       if(st2.empty())
       {
       while(!st1.empty())
        {
            int topa = st1.top();
            st1.pop();
            st2.push(topa);
        }
       }
        int ans= st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        if(empty()) return -1;
        if(st2.empty())
        {
        while(!st1.empty())
        {
            int topa = st1.top();
            st1.pop();
            st2.push(topa);
        }
        }
        int ans = st2.top();
        return ans;
    }
    
    bool empty() {
        
        return st1.empty()&&st2.empty();
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