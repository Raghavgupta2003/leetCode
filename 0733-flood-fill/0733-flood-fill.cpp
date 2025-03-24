class Solution {
public:
   void dfs(vector<vector<int>>& matrix, int i, int j, int prevColor, int color){
    if(i<0 || i>=matrix.size() || j>=matrix[0].size() || j<0) return;
    if (matrix[i][j] != prevColor || matrix[i][j] == color) return;

    if(matrix[i][j] == prevColor) matrix[i][j] = color;
    dfs(matrix, i+1, j, prevColor, color);
    dfs(matrix, i, j+1, prevColor, color);
    dfs(matrix, i-1, j, prevColor, color);
    dfs(matrix, i, j-1, prevColor, color);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> matrix = image;
        int i=sr;
        int j=sc;
        int prevColor = matrix[i][j];

        dfs(matrix, i, j, prevColor, color);

        return matrix;
        
    }
};