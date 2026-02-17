class MyQueue {
public:
stack<int>st,helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(helper.empty()){
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
        }
        int x=helper.top();
        helper.pop();
        return x;
    }
    
    int peek() {
        if(helper.empty()){
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
        }
        int x=helper.top();
        return x;
    }
    
    bool empty() {
        return helper.size()==0 && st.size()==0;
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