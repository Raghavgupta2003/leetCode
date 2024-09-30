class CustomStack {
public:
    int size;
    stack<int> st;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st.size()<size){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.size()==0) return -1;
        else{
            int x = st.top();
            st.pop();
            return x;
        }
    }
    
    void increment(int k, int val) {
        if(st.size()<k){
            stack<int> temp;
            while(st.size()>0){
                temp.push(st.top()+val);
                st.pop();
            }

            while(temp.size()>0){
                st.push(temp.top());
                temp.pop();
            }
        }
        else{
            stack<int> temp;
            while(st.size()>k){
                temp.push(st.top());
                st.pop();
            }
            while(st.size()>0){
                temp.push(st.top()+val);
                st.pop();
            }
            while(temp.size()>0){
                st.push(temp.top());
                temp.pop();
            }

        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */