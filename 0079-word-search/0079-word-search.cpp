class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word){
        if(board[i][j] != word[k]) return false;
        if(k == word.size()-1) return true;
        

        char temp = board[i][j];
        board[i][j] = '#';
        for(int m=0; m<4; m++){
            int nr = i+delrow[m];
            int nc = j+delcol[m];

            if(nr>=0 && nc>=0 && nr<board.size() && nc < board[0].size()){
                if(board[nr][nc] != '#'){
                    if(dfs(nr, nc, k+1, board, word)) return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    string str = "";
                    if(dfs(i, j, 0, board, word)) return true;
                }
            }
        }

        return false;
    }
};