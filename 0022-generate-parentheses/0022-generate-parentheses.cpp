class Solution {
public:
    bool valid(string str){
        int cnt = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '(') cnt++;
            else{
                cnt--;
                if(cnt < 0) return false;  //opening brackets less before closing bracket
            }
        }

        return cnt == 0;
    }
    void help(int n, vector<string>& ans, string str){
        if(str.size() == 2*n){
            if(valid(str)) ans.push_back(str);
            return;
        }

        // "(" pick
        help(n, ans, str+"(");

        //")" pick
        help(n, ans, str+")");

    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        help(n, ans, str);
        return ans;
    }
};