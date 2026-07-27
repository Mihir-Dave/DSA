class MinStack {
public:
    vector<int> st;
    //int min_ele;
    vector<int> min_ele;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
        if(min_ele.empty() || min_ele.back() >= value){
            min_ele.push_back(value);
        }
    }
    
    void pop() {
        if(min_ele.back() == st.back() && (!st.empty())) {
            if(!min_ele.empty()) min_ele.pop_back();
        }
    
        if(!st.empty()) st.pop_back();

    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        if(!min_ele.empty()) return min_ele.back();
        else return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */