class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()>0){  
                if((st.top()=='A' && s[i]=='B') || (st.top()=='C' && s[i]=='D')) {
                    // cout<<"poped"<<st.top()<<endl;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                    // cout<<"inserted"<<s[i]<<endl;
                }
            }
            else{
                st.push(s[i]);
            }
       }

        return st.size();
    }
};