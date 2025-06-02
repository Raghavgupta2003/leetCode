class Solution {
public:

    bool isvalid(string bracket){
        int cnt = 0;
        for(int i=0; i<bracket.size(); i++){
            if(bracket[i] == '(') cnt++;
            if(bracket[i] == ')') cnt--;
        }
        if(cnt ==0 ) return true;
        return false;
    }
    void generate(int open, int close,int n, vector<string>& v, string &bracket, int brack){
        if(bracket.size() == 2*brack && isvalid(bracket)){
            v.push_back(bracket);
            return;
        }

        if(open < brack){
            bracket += "(";
            generate(open+1, close, n+1, v, bracket, brack);
            bracket.pop_back();
        }

        if(close < open){
            bracket += ")";
            generate(open, close+1, n+1, v, bracket, brack);
            bracket.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string bracket = "";
        vector<string> v;
        generate(0,0,0, v, bracket, n);
        return v;
    }
};