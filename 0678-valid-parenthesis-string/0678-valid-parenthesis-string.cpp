class Solution {
public:
    bool checkValidString(string s) {
        //since (*) can give
        // cnt = 0 => ""
        // cnt = 1 => "("
        // cnt = -1 =>")"

        //since -1 is not possible for it, so we keep 2 pointers min and max here
        //and perform with these
        //at end any one is zero then return true;
        
        if(s[0] == ')') return false;
        int max = 0;
        int min = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                max++;
                min++;
            }else if(s[i] == ')'){
                max--;
                min--;
            }
            else{
                min--;
                max++;
            }

            if(min<0) min = 0;
            if(max < 0) return false;
        }

        return min==0;
    }
};