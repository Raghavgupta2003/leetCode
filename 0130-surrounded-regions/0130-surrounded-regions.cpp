class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    void DFS(int i, int j, vector<vector<char>>& board){
        board[i][j] = 'Y';

        for(int k=0; k<4; k++){
            int ni = i + delrow[k];
            int nj = j + delcol[k];

            if(ni >= 0 && nj >= 0 && ni < board.size()  && nj < board[0].size()){
                if(board[ni][nj] == 'O'){
                    DFS(ni, nj, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //question is something like we cannot move from "o regin" to out of the grid
        //so, in this question i will do  DFS traversal on boundaryies where "o" founded
        //and mark them as "y"
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') DFS(i, 0, board);

            if(board[i][n-1] == 'O') DFS(i, n-1, board);
        }

         for(int j=0; j<n; j++){
            if(board[0][j] == 'O') DFS(0, j, board);

            if(board[m-1][j] == 'O') DFS(m-1, j, board);
        }

        //Now mark all "o" (present in middle, whose no path to out of board) as "x"
        //mark again "y" as "o";

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }

    }
};