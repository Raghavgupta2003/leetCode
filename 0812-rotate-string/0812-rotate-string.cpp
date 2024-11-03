class Solution {
public:
    bool rotateString(string s, string goal) {
       //HINT :
       // If we concatenate a string with itself, it will
       // contain all rotations as substring in it.

        if(goal.length()!=s.length()) return false;

       s = s+s;

       for(int i=0;i<s.length();i++){
        for(int j=0;j<goal.length();j++){
            if(s[i]==goal[j]){
                string str = s.substr(i,goal.length());
                 if(str == goal) return true;
            }
        }
       }
        return false;
    }
};