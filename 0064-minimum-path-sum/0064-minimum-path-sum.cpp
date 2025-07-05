class Solution {
public:
    int PathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
      
        if(i>=grid.size() || j>=grid[0].size() ) return 1e9;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[grid.size()-1][grid[0].size()-1];

        if(dp[i][j] != -1) return dp[i][j];

        int right = grid[i][j] + PathSum(i, j+1, grid, dp);
        int down  = grid[i][j] + PathSum(i+1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return PathSum(0, 0, grid, dp);
    }
};