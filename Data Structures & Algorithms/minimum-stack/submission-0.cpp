class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {}
    
    void push(int val) {
        // we have to push on both the stacks 
        st.push(val);
        int val1=min(val,minst.empty()?val:minst.top());
        minst.push(val1);
    }
    
    void pop() {
        st.pop();
        // for consistency we have to delete from the minst
        minst.pop();
        
    }
    
    int top() {
       return  st.top();
        
    }
    
    int getMin() {
       return minst.top();
    }
};
