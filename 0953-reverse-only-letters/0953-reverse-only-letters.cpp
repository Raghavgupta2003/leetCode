class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0;
        int r=s.length()-1;

        while(l<=r){
            
               
            
            if(isalpha(s[r])==0){
                r--;
                continue;
            }
            if(isalpha(s[l])==0){
                l++;
                continue;
            }

             swap(s[l],s[r]);
                l++;
                r--;


           
            
        }
        return s;
    }
};