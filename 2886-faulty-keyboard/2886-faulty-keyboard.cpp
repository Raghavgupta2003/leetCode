class Solution {
public:
    string finalString(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='i'){
                reverse(s.begin(),s.begin()+i);
            }
        }
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='i'){
                str+=s[i];
            }
        }
        return str;
    }
};