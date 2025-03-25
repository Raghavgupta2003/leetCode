//-----------------------by using 2 stacks---------------------
// class MinStack {
// public:
//     stack<int> st;
//     stack<int> helper;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);

//         if(helper.size() == 0) helper.push(val); // initially
//         else{
//             if(val < helper.top()) helper.push(val); // pushhing minimum
//             else helper.push(helper.top()); // if val is not minimum then previous one is minimum.
//         } 
//     }
    
//     void pop() {
//         if(st.size()>0) st.pop();
//         if(helper.size()>0) helper.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return helper.top();
//     }
// };

//------------------------------approach 2 by vector----------------------

class MinStack {
public:
    vector<int> v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i=0; i<v.size(); i++){
            if(v[i] < mini) mini = v[i];
        }
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