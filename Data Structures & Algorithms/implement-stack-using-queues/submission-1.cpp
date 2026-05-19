class MyStack {
public:
    // implimentation of stacks using queueu 
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // we have to push the element in the q2 and then add the element from q1 to q2 
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);

        // we can use only one 

    }
    
    int pop() {
        int a=q1.front();
        q1.pop();
        return a;
        
    }
    
    int top() {
        return q1.front();   
    }
    
    bool empty() {
        return q1.empty();
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