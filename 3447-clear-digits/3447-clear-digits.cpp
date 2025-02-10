class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0; i<s.size();i++){
            if(st.size()==0) st.push(s[i]);
            else if(st.size()>0 && isalpha(st.top()) && isdigit(s[i])){
                st.pop();
            }
            else st.push(s[i]);
        }
        
        string ans = "";
        while(st.size()>0){
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }

        return ans;
    }
};