class Solution {
public:
    int prio(char op){
        int priority=0;
        if(op=='+' || op=='-') return priority=1;
        if(op=='/' || op=='*') return priority=2;
        return priority;
    }
    int cal(int v1, int v2,char op){
            int ans=0;
            if(op=='+') ans =  v1+v2;
            else if(op=='-') ans = v1-v2;
            else if(op=='*') ans = v1*v2;
            else if(op=='/') ans = v1/v2;
            return ans;
        }
    int calculate(string str) {
        string s="";
        for(int i=0;i<str.size();i++){
            if(str[i]==' ') continue;
            else s+=str[i];
        }
        // cout<<s;
        stack<int> st;
        stack<char> op;
        string x="";
       for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                x+=s[i];
            }
            else{
                cout<<x<<endl;
                st.push(stoi(x));
                x="";
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    int val2=st.top();
                    st.pop(); 
                    int val1=st.top();
                    st.pop();
                    char opr=op.top();
                    op.pop();
    
                    int ans=cal(val1,val2,opr);
                    st.push(ans);
                }
                op.push(s[i]);   
            }
       }
       st.push(stoi(x));
        while(op.size()>0){
            int val2=st.top();
            st.pop(); 
            int val1=st.top();
            st.pop();
            char opr=op.top();
            op.pop();
            
            int ans=cal(val1,val2,opr);
            st.push(ans);
        }
        return st.top();
    }
};