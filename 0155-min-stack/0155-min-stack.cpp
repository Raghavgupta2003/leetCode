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

// class MinStack {
// public:
//     vector<int> v;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         v.push_back(val);
//     }
    
//     void pop() {
//         v.pop_back();
//     }
    
//     int top() {
//         return v[v.size()-1];
//     }
    
//     int getMin() {
//         int mini = INT_MAX;
//         for(int i=0; i<v.size(); i++){
//             if(v[i] < mini) mini = v[i];
//         }
//         return mini;
//     }
// };


//-------------------Using one stack and MATH----------------------------

class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push(val);
            mini = val;
        }
        else if(val >= mini){
            st.push(val);
        }
        else{  // val < mini
            long long fake = 2LL*val - mini;
            st.push(fake);
            mini = val;
        }
    }
    
    void pop() { 
        if(st.top() >= mini){
            st.pop();
        }
        else{ // st.top()<mini  means fake node
            // old minimum
            long long oldmin = 2LL * mini - st.top();
            mini = oldmin;
            st.pop();
        }
       
    }
    
    int top() {
        if(st.top() < mini){
           return mini;
        }else{
            return st.top();
        }
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