class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int m = v.size();
        int n = v[0].size();
        int i=0;
        int j=n-1;

        while(i<m && j>=0){
            if(target == v[i][j]) return true;
            if(target<v[i][j]){
                j--;
            }
            else{
                i++;
            }
        }

        return false;
        
    }
};