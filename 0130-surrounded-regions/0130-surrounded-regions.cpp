class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited){
        // if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(grid[i][j] == 'X') return;

        visited[i][j] = 1;

        for(int k=0; k<4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            
            if(nrow >=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size()){
                if(!visited[nrow][ncol]) dfs(nrow, ncol, grid, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            if(board[0][j] == 'O' ) dfs(0, j, board, visited); //upper boundry row
            if(board[m-1][j] == 'O' ) dfs(m-1, j, board, visited); //lower boundry row
        }

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O' ) dfs(i, 0, board, visited);
            if(board[i][n-1] == 'O' ) dfs(i, n-1, board, visited);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(board[i][j] == 'O') board[i][j] = 'X';
                }
            }
        }
    }
};