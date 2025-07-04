class Solution {
public:
    int count(int i, int j, vector<vector<int>>& obstacleGrid,  vector<vector<int>>& dp){
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1) return 0;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[i].size()-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int right = count(i, j+1, obstacleGrid, dp);
        int down = count(i+1, j, obstacleGrid, dp);

        return  dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(0, 0, obstacleGrid, dp);
    }
};