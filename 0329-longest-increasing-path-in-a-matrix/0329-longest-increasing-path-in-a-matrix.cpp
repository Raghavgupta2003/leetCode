class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    int path(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 1;
       
        for(int k=0; k<4; k++){
            int r = i+delrow[k];
            int c = j+delcol[k];
            if(r>=0 && c>=0 && r<matrix.size() && c<matrix[0].size()){
                if(matrix[i][j] < matrix[r][c]){
                    maxi = max(maxi, 1+path(r, c, matrix, dp));
                }
            }
        }

        return dp[i][j] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, path(i, j, matrix, dp));
            }
        }

        return ans;
    }
};