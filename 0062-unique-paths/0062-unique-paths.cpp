class Solution {
public:
    // int paths(int i, int j, int m, int n, vector<vector<int>>& dp){
    //     if(i == m-1 && j==n-1) return 1;
    //     if(i>=m || j>=n) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int right = paths(i, j+1, m, n, dp);
    //     int down = paths(i+1, j, m, n, dp);

    //     return dp[i][j] = right + down;
    // }

    int paths(int m, int n, vector<vector<int>>& dp){
        if(m == 0 && n==0) return 1;
        if(m<0 || n<0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        int left = paths(m, n-1, dp);
        int up = paths(m-1, n, dp);

        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return paths(0, 0, m, n, dp);

        return paths(m-1, n-1, dp);
    }
};