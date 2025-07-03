class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() <= k){
            string str = "";
            for(int i=0; i<s.size(); i++){
                str += char(s[i]+1);
            }
            s+=str;
        }
        return s[k-1];
    }
};