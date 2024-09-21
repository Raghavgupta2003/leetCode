class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        int row=0;
        int col=0;
        int dir=1; //up
        vector<int> v;
        while(row<m && col<n){
            if(dir==1){
                while(row>0 && col<n-1){
                    v.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                v.push_back(mat[row][col]);
                if(col==n-1) row++;
                else col++;
                dir=0;
            }
            else{
                while(col>0 && row<m-1){
                    v.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                v.push_back(mat[row][col]);
                if(row==m-1) col++;
                else row++;
                dir=1;
            }
        }

        return v;
    }
};