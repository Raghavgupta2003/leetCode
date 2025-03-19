// class Solution {
// public:
//     int helper(int idx1, int idx2, string& str1, string& str2, vector<vector<int>>& dp){
//         if(idx1<0 || idx2<0) return 0;
        
//         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

//         if(str1[idx1] == str2[idx2]) return dp[idx1][idx2] = 1 + helper(idx1-1, idx2-1, str1, str2, dp);

//         return  dp[idx1][idx2] = 0 + max(helper(idx1-1, idx2, str1, str2, dp), helper(idx1, idx2-1, str1, str2, dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();

//         vector<vector<int>> dp(n1, vector<int>(n2, -1));

//         return helper(n1-1, n2-1, text1, text2, dp);
//     }
// };


//-------------------------TABULATION----------------------


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // since in base case we find (idx < 0)
        // so we make dp of (n+1) size to use indexes (1 to <= n)
        // so index 0 is treated for idx<0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};