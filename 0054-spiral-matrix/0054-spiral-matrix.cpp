class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;
        int top=0;
        int bottom=m-1;
        int left = 0;
        int right = n-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom && left<=right){
                for(int i= right; i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(top<=bottom && left<=right){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return v;
        
    }
};