class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v;
        if(m*n!=original.size()) return v;
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
};