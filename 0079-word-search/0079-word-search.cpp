class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    bool dfs(int i, int j, vector<vector<char>>& board, int k, string word){
        if(word[k] != board[i][j]) return false;
        if(word.size() == k+1) return true;
    
        int temp = board[i][j];
        board[i][j] = '#';

        for(int p=0; p<4; p++){
            int r = i+delrow[p];
            int c = j+delcol[p];

            if(r>=0 && c>=0 && r<board.size() && c<board[0].size()){
                if(board[r][c]!='#'){
                    if(dfs(r, c, board, k+1, word)) return true;
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
                    if(dfs(i, j, board, 0, word)) return true;
                }
            }
        }

        return false;
    }
};