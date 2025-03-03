// class Solution {
// public:
//     int path(int row, int col, vector<vector<int>>& triangle){
//         if(row >= triangle.size()) return 0;
        
//         int down = triangle[row][col] + path(row+1, col, triangle);
//         int diagonal =  triangle[row][col] + path(row+1, col+1, triangle);

//         return min(down, diagonal);

//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return path(0,0,triangle);
//     }
// };

//----------------------MEMORIZATION--------------------------


class Solution {
public:
    int path(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(row >= triangle.size()) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + path(row+1, col, triangle, dp);
        int diagonal =  triangle[row][col] + path(row+1, col+1, triangle, dp);

        return dp[row][col] = min(down, diagonal);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return path(0,0,triangle,dp);
    }
};