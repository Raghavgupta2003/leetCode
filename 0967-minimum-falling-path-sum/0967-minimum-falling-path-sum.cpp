// class Solution {
// public:
//     int path(int row, int col, vector<vector<int>>& matrix){
        
//         if(col >= matrix[0].size() || col < 0) return 1e9;
//         if(row == 0) return matrix[0][col];
       
//         int down = matrix[row][col] + path(row-1, col, matrix);
//         int leftdiagonal = matrix[row][col] + path(row-1, col-1, matrix);
//         int rightdiagonal = matrix[row][col] + path(row-1, col+1, matrix);
        

//         return min(down, min(leftdiagonal, rightdiagonal));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int mini = INT_MAX;
//         int row = matrix.size()-1;
//         // calling recursion for last column
//         for(int col=0; col<matrix[0].size(); col++){
//             int x = path(row, col, matrix);
//             mini = min(x, mini);
//         }
//         return mini;
//     }
// };

// //------------------MEMORIZATION------------------------
// class Solution {
// public:
//     int path(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
//         if(col >= matrix[0].size() || col < 0) return 1e9;

//         if(row == 0) return matrix[0][col];

//        if(dp[row][col] != -1) return dp[row][col];

//         int down = matrix[row][col] + path(row-1, col, matrix, dp);
//         int leftdiagonal = matrix[row][col] + path(row-1, col-1, matrix, dp);
//         int rightdiagonal = matrix[row][col] + path(row-1, col+1, matrix, dp);
        

//         return dp[row][col] = min(down, min(leftdiagonal, rightdiagonal));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int mini = INT_MAX;
//         int row = matrix.size()-1;
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         // calling recursion for last column
//         for(int col=0; col<matrix[0].size(); col++){
//             int x = path(row, col, matrix, dp);
//             mini = min(x, mini);
//         }
//         return mini;
//     }
// };


//------------------Tabulation------------------------
class Solution {
public:
       int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size()-1;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        // base case -> filling first row of dp

        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int left = 1e9;
                int down = 1e9;
                int right = 1e9;
                if(j>0) left = matrix[i][j] + dp[i-1][j-1];
                 down = matrix[i][j] + dp[i-1][j];
                 if(j<n-1) right = matrix[i][j] + dp[i-1][j+1];

                 dp[i][j] = min(down, min(left, right));
            }
        }

        // we have answers stored in last row of dp

        int mini = INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            mini = min(dp[n-1][i], mini);
        }
        return mini;
    }
};
