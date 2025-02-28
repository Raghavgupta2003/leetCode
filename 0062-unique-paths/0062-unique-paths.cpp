// class Solution {
// public:
//     int count(int i, int j, int m, int n){
    
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;
        

//         //down
//         int left = count(i+1, j, m, n);
//         int right = count(i, j+1, m, n);

//         return left + right;
//     }
//     int uniquePaths(int m, int n) {
//         return count(0, 0, m ,n);
//     }
// };


//--------------------Memorization----------------------

class Solution {
public:
    int count(int i, int j, int m, int n, vector<vector<int>> &dp){
    
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        //down
        int left = count(i+1, j, m, n, dp);
        // right
        int right = count(i, j+1, m, n, dp);

        return dp[i][j] = left + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(0, 0, m ,n, dp);
    }
};