// class Solution {
// public:
//     int minpath(int idx, int last, vector<vector<int>>& triangle){
//         if(idx >= triangle.size()) return 0;
        
//         int mini = 1e9;
//         for(int i=last; i<triangle[idx].size(); i++){
//             int x = triangle[idx][i] + minpath(idx+1, i, triangle);
//             mini = min(mini, x);
//         }
//         return mini;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         return minpath(0,0,triangle);
        
//     }
// };


// class Solution {
// public:
//     int minpath(int idx, int col, vector<vector<int>>& triangle){
//         if(idx >= triangle.size()) return 0;
        
//         int down = triangle[idx][col] + minpath(idx+1, col, triangle);
//         int diagonal = triangle[idx][col] + minpath(idx+1, col+1, triangle);
//         return min(down, diagonal);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         return minpath(0,0,triangle);
        
//     }
// };

//-------------------MEMORIZATION----------------

class Solution {
public:
    int minpath(int idx, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(idx >= triangle.size()) return 0;
        
        if(dp[idx][col] != -1) return dp[idx][col];
       
        int down = triangle[idx][col] + minpath(idx+1, col, triangle,dp);
        int diagonal = triangle[idx][col] + minpath(idx+1, col+1, triangle,dp);
        return dp[idx][col] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minpath(0,0,triangle,dp);
        
    }
};