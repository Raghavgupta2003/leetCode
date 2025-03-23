//-------------------Wrong answer-------------------------
// class Solution {
// public:
//     int helper(int idx, string s, vector<int>& dp){
//         if(idx == 0 ) return 1;
//         if(s[idx] == '0') return 0;

//         if(dp[idx]!=-1) return dp[idx];

//         //picking one element
//         int left = helper(idx-1, s, dp);
//         //picking two elements
//         int right = 0;
//         if(idx>0 && (s[idx-1] == '1' || (s[idx-1] == '2' && s[idx] <= '6'))){
//             right = helper(idx-2, s, dp);
//         }

//         return dp[idx] = left + right;
//     }
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n, -1);
//         return helper(n-1, s, dp);
//     }
// };

//-----------------------------------------------------------------

class Solution {
public:
    int helper(int idx, string s, vector<int>& dp){
        int n = s.size();
        if(idx >= n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx]!=-1) return dp[idx];

        //picking one element
        int left = helper(idx+1, s, dp);
        //picking two elements
        int right = 0;
        if(idx != n-1 && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))){
            right = helper(idx+2, s, dp);
        }

        return dp[idx] = left + right;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, dp);
    }
};