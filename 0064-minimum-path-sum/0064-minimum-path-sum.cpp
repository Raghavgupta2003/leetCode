// class Solution {
// public:
//     int pathsum(int i, int j, int m, int n, vector<vector<int>>& grid){
//           if(i==m-1 && j==n-1) return grid[m-1][n-1];
//           if(i>=m || j>=n) return 201;

//           int left = grid[i][j] + pathsum(i+1, j, m, n, grid);
//           int right = grid[i][j] + pathsum(i, j+1, m, n, grid);

//           return min(left, right);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         return pathsum(0, 0, m, n, grid);
//     }
// };

//---------------------------MEMORIZATION---------------------

// class Solution {
// public:
//     int pathsum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
//           if(i==m-1 && j==n-1) return grid[m-1][n-1];
//           if(i>=m || j>=n) return 1e9;
          
//           if(dp[i][j] != -1) return dp[i][j];
//           long long left = grid[i][j] + pathsum(i+1, j, m, n, grid, dp);
//           long long right = grid[i][j] + pathsum(i, j+1, m, n, grid, dp);

//           return dp[i][j] = min((int)left, (int)right);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n,-1));
//         return pathsum(0, 0, m, n, grid, dp);
//     }
// };

//--------------------------TABULATION---------------------

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0] = grid[0][0];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int l = 1e9;
                    int r = 1e9;

                    if(i>0) l = grid[i][j] + dp[i-1][j];
                    if(j>0) r = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(l,r);
                }
            }
        }

        return dp[m-1][n-1];
    }
};