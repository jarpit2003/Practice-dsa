class MinStack {
public:
stack<pair<int,int>>st;
int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
      st.push({val,mini});  
      mini = min(mini,val);
    }
    
    void pop() {
       if(mini == st.top().first) mini = st.top().second;
       st.pop(); 
    }
    
    int top() {
        int ans = st.top().first;
        return ans;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */