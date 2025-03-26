class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v.push_back(grid[i][j]);
            }
        }
        // we will sort the array
        // to make all elements equal we take mid element of sorted array
        // we try to make all elements equal to mid element(targetElement)
        // how many difference b/w targetElement and element 
        // (targetEle - v[i])%x == 0)  shows can we make it equal to target by adding or subtrating
        // (targetEle - v[i])/x gives number of required operations.
        sort(v.begin(), v.end());

        int idx = v.size()/2;
        int targetEle = v[idx];

        int cnt = 0;
        for(int i=0; i<idx; i++){
            if((targetEle - v[i])%x == 0) cnt +=  (targetEle - v[i])/x;
            else return -1;
        }
        for(int i=idx+1; i<v.size(); i++){
            if((v[i] - targetEle)%x == 0) cnt +=  (v[i] - targetEle)/x;
            else return -1;
        }

        return cnt;
    }
};