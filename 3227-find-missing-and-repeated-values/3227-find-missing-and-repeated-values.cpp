class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> hash;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                hash[grid[i][j]]++;
            }
        }
        int repeated = 0;
        for(auto it : hash){
            if(it.second > 1){
                repeated = it.first;
                break;
            }
        }
        int not_found = 0;
        for(int i=1; i<=m*n; i++){
            if(hash.find(i)==hash.end()){
                not_found = i;
                break;

            }
        }


        return {repeated, not_found};
    }
};