class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int cnt = 0;
        // pushing inbalance string
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push('[');
            }
            else if(st.size()>0 && st.top()=='[' && s[i]==']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        //number of only '[' bracket 
        // number of imbalance string

        int  imbalanceCnt = st.size()/2;

        return (imbalanceCnt+1)/2;
    }
};