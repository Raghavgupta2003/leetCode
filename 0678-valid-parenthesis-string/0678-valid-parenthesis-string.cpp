class Solution {
public:
    // Here in this question, we play with indexes
    // As we there is a * before close then we have to treat it like '('
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;

        if(s[0] == ')') return false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == '*') star.push(i);
            else if(s[i] == ')'){
                if(st.size() > 0) st.pop();
                else if(star.size() > 0) star.pop();
                else return false; //st.size() == 0 && star.size()==0 
            }
        }

        while(st.size()>0 && star.size()>0){
            if(st.top() < star.top()){
                st.pop();
                star.pop();
            }else return false;
        }

        return st.size() == 0;
    }
};