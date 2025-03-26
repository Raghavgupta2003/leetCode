class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void helper(int idx, string s, vector<string>& v, vector<vector<string>>& ans){
        if(idx >= s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            string str = s.substr(idx, i - idx + 1);
            if(isPalindrome(str)){
                v.push_back(str);
                helper(i+1, s, v, ans);
                v.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
       
        helper(0, s, v, ans);
        return ans;
    }
};