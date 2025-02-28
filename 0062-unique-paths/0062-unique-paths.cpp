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

// class Solution {
// public:
//     int count(int i, int j, int m, int n, vector<vector<int>> &dp){
    
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];

//         //down
//         int left = count(i+1, j, m, n, dp);
//         // right
//         int right = count(i, j+1, m, n, dp);

//         return dp[i][j] = left + right;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return count(0, 0, m ,n, dp);
//     }
// };


//--------------------Tabulation----------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)   dp[0][0] = 1;
                else{
                    int l = 0;
                    int r = 0;
                    if(i>0) l = dp[i-1][j];
                    if(j>0) r = dp[i][j-1];

                    dp[i][j] = l+r;
                }
            }
        }

        return dp[m-1][n-1];
    }
};