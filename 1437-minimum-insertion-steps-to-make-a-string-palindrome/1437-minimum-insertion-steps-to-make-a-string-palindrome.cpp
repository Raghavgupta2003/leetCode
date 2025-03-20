class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 1));

        //basecase

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
        }

        //dp

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lenOfCommonSubseq = dp[n][n];

        int minimumInsertions = s.size() - lenOfCommonSubseq;

        return minimumInsertions;
    }
};