class Solution {
public:
    vector<string> ans;
    bool isvalid(string s){
        if(s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val>=0 && val<=255;
    }
    void solve(string &s, int idx, int part, string cur){
        int n = s.size();
        if(idx == n && part == 4){
            cur.pop_back();
            ans.push_back(cur);
        }

        if(idx+1 <= n) solve(s, idx+1, part+1, cur + s.substr(idx, 1) + ".");

        if(idx+2 <= n && isvalid(s.substr(idx,2))) solve(s, idx+2, part+1, cur + s.substr(idx, 2) + ".");

         if(idx+3 <= n && isvalid(s.substr(idx,3))) solve(s, idx+3, part+1, cur + s.substr(idx, 3) + ".");
    }
    vector<string> restoreIpAddresses(string s) {
        string curr="";
        solve(s, 0, 0, curr);
        return ans;
    }
};