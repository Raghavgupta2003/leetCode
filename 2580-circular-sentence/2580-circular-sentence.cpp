class Solution {
public:
    bool isCircularSentence(string s) {
        int len = s.length();
        if(s[0] != s[len-1]) return false;

        for(int i=0;i<s.length();i++){
            if(s[i+1] == ' '){
                if(s[i]!=s[i+2]){
                    return false;
                }
            }
        }

        return true;
    }
};