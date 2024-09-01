class Solution {
public:

 vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v;
      
        vector<int> helper;
        for(int i=0;i<original.size();i++){
            helper.push_back(original[i]);
            if(helper.size()==n){
                v.push_back(helper);
               helper.clear();
            } 
                     
        }

        return v;
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int m = mat.size();
        int n= mat[0].size();

        if(m*n != r*c) return mat;
        vector<int> original;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                original.push_back(mat[i][j]);
            }
        }
  
        vector<vector<int>> ans = construct2DArray(original, r,c);
        return ans; 
    }
};