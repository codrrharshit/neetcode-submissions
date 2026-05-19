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
        // size of the stack should be from size-1 and the last lement 
        for(int i=st1.size()-1;i>0;i--){
            st2.push(st1.top());
            st1.pop();
        }

        int top=st1.top();
        st1.pop();
        // we have to push back all the elements of the stack2 into 1 
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    int peek() {
        for(int i=st1.size()-1;i>0;i--){
            st2.push(st1.top());
            st1.pop();
        }

        int top=st1.top();
        // we have to push back all the elements of the stack2 into 1 
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    bool empty() {
        return st1.empty();
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