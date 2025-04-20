class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        visited[i][j] = 1;

        for(int k=0; k<4; k++){
            int nrow = i+delrow[k];
            int ncol = j+delcol[k];

            if(nrow >=0 && ncol >=0 && nrow<grid.size() && ncol<grid[0].size()){
                if(!visited[nrow][ncol] && grid[nrow][ncol] == 1)dfs(nrow, ncol, visited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //we apply dfs on boundry
        //if we find 1 on boundry apply dfs on them and mark them visited
        //so, we cannot move out of grid by that land
        //now count unvisited l in the array its our ans.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        //boudry dfs column
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) dfs(i, 0, visited, grid);

            if(grid[i][n-1] == 1) dfs(i, n-1, visited, grid);
        }
        //boudry dfs row
        for(int j=0; j<n; j++){
            if(grid[0][j] == 1) dfs(0, j, visited, grid);

            if(grid[m-1][j] == 1) dfs(m-1, j, visited, grid);
        }

        //count unvisited 1
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};