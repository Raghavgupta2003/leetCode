// class Solution {
// public:
//     bool valid(string str){
//         int cnt = 0;
//         for(int i=0; i<str.size(); i++){
//             if(str[i] == '(') cnt++;
//             else{
//                 cnt--;
//                 if(cnt < 0) return false;  //opening brackets less before closing bracket
//             }
//         }

//         return cnt == 0;
//     }
//     void help(int n, vector<string>& ans, string str){
//         if(str.size() == 2*n){
//             if(valid(str)) ans.push_back(str);
//             return;
//         }

//         // "(" pick
//         help(n, ans, str+"(");

//         //")" pick
//         help(n, ans, str+")");

//     }
//     vector<string> generateParenthesis(int n) {
//         string str = "";
//         vector<string> ans;
//         help(n, ans, str);
//         return ans;
//     }
// };


//-----------------------------------------------------

class Solution {
public:
    void help(int n, vector<string>& ans, string str, int open, int close){
        if(str.size() == 2*n){
            if(open == close) ans.push_back(str);
            return;
        }

        // "(" pick
        if(open < n) 
        help(n, ans, str+"(", open+1, close);

        //")" pick
        if(close < open)
        help(n, ans, str+")", open, close+1);

    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        int open = 0;
        int close = 0;
        help(n, ans, str, open, close);
        return ans;
    }
};