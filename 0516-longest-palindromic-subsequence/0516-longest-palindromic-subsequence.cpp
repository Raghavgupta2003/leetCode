// class Solution {
// public:
//     int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){
//         if(idx1<0 || idx2<0) return 0;
        
//         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

//         if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] =  1 + helper(idx1-1, idx2-1, s1, s2, dp);
        
//         return dp[idx1][idx2] = 0 + max(helper(idx1-1, idx2, s1, s2, dp), helper(idx1, idx2-1, s1, s2, dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());

//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int> (n, -1));

//         return helper(n-1, n-1, s1, s2, dp);
//     }
// };


//-------------------------------------------------------------------


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        //base case
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }  
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
        }    
        //dp

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];    
    }
};