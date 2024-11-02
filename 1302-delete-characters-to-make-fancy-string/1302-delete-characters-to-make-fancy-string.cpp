class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        result+=s[0];
        int freq = 1;

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                freq++;
                if(freq<=2){
                    result+=s[i];
                }
            }
            else{
                result+=s[i];
                freq = 1;
            }
        }

        return result;
    }
};