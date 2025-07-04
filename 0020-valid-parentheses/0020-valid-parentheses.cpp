class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else if(st.size()>0  && ch==')' && st.top()=='(') st.pop();
            else if(st.size()>0  && ch=='}' && st.top()=='{') st.pop();
            else if(st.size()>0  && ch==']' && st.top()=='[') st.pop();
            else st.push(ch);
   
        }
        if(st.size()>0) return false;
        return true;
        
    }
};