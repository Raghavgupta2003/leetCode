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

class Solution {
public:
    int pathsum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
          if(i==m-1 && j==n-1) return grid[m-1][n-1];
          if(i>=m || j>=n) return 201;
          
          if(dp[i][j] != -1) return dp[i][j];
          int left = grid[i][j] + pathsum(i+1, j, m, n, grid, dp);
          int right = grid[i][j] + pathsum(i, j+1, m, n, grid, dp);

          return dp[i][j] = min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return pathsum(0, 0, m, n, grid, dp);
    }
};