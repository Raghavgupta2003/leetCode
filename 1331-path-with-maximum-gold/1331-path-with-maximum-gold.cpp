class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& grid, int &maxgold, int currval){
        currval += grid[i][j];
        maxgold = max(currval, maxgold);

        int node = grid[i][j];
        grid[i][j] = 0;

        for(int k=0; k<4; k++){
            int r = i + delrow[k];
            int c = j + delcol[k];

            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size()){
                if(grid[r][c] != 0){
                    dfs(r, c, grid, maxgold, currval);
                }
            }
        }

        grid[i][j] = node;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxi = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0){
                    int maxgold = 0;
                    dfs(i, j, grid, maxgold, 0);
                    maxi = max(maxi, maxgold);
                }
            }
        }

        return maxi;
    }
};