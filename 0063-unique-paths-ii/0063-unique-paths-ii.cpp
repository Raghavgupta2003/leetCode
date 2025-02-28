// class Solution {
// public:
//     int count(int i, int j, int m, int n,vector<vector<int>>& arr){
//         if(i<m && j<n && arr[i][j] == 1) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;

//         int left = count(i+1, j, m, n, arr);
//         int right = count(i, j+1, m, n, arr);

//         return left + right; 
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         return count(0, 0, m, n,obstacleGrid);
//     }
// };

//----------------------MEMORIZATION----------------

// class Solution {
// public:
//     int count(int i, int j, int m, int n,vector<vector<int>>& arr, vector<vector<int>>& dp){
//         if(i<m && j<n && arr[i][j] == 1) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;

//         if(dp[i][j] !=-1) return dp[i][j];

//         int left = count(i+1, j, m, n, arr, dp);
//         int right = count(i, j+1, m, n, arr, dp);

//         return dp[i][j] = left + right; 
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return count(0, 0, m, n,obstacleGrid, dp);
//     }
// };


//------------------TABULATION---------------

class Solution {
public:
    int count(int i, int j, int m, int n,vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i<m && j<n && arr[i][j] == 1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j] !=-1) return dp[i][j];

        int left = count(i+1, j, m, n, arr, dp);
        int right = count(i, j+1, m, n, arr, dp);

        return dp[i][j] = left + right; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[0][0] = 1;
                else{
                    int l=0;
                    int r=0;
                    
                    if(i>0){
                        l = dp[i-1][j];
                    }
                    if(j>0){
                        r = dp[i][j-1];
                    }

                    dp[i][j] = l+r;
                }
            }
        }
        return abs(dp[m-1][n-1]);
    }
};