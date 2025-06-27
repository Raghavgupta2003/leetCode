class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        visited[i][j] = 1;

        for(int k=0; k<4; k++){
            int ir = i + delrow[k];
            int ic = j + delcol[k];

            if(ir >= 0 && ic >= 0 && ir < grid.size() && ic < grid[0].size()){
                if(grid[ir][ic] == 1 && !visited[ir][ic]){
                    DFS(ir, ic, grid, visited);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //APPLY DFS ON BOUNDARIES WHERE LAND FOUND AND MARK AS VISITED 
        //NOW, COUNT THE NUMBER OF CELLS HAVING LAND(1) which aare not visited

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) DFS(i, 0, grid, visited);

            if(grid[i][n-1] == 1) DFS(i, n-1, grid, visited);
        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 1) DFS(0, j, grid, visited);

            if(grid[m-1][j] == 1) DFS(m-1, j, grid, visited);
        }
        
        //counting unvisited land
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(grid[i][j] == 1) cnt++;
                }
            }
        }

        return cnt;

    }
};