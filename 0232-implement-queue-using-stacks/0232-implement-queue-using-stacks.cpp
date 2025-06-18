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
        if(st1.empty()) return -1;
       while(!st1.empty())
        {
            int topa = st1.top();
            st1.pop();
            st2.push(topa);
        }
        int ans= st2.top();
        st2.pop();
        while(!st2.empty())
        {
            int topa = st2.top();
            st2.pop();
            st1.push(topa);
        }
        return ans;
    }
    
    int peek() {
        if(st1.empty()) return -1;
        while(!st1.empty())
        {
            int topa = st1.top();
            st1.pop();
            st2.push(topa);
        }
        int ans = st2.top();
        while(!st2.empty())
        {
            int topa = st2.top();
            st2.pop();
            st1.push(topa);
        }
        return ans;
    }
    
    bool empty() {
        if(st1.empty()) return  true;
        return false;
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