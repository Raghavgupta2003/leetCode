class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int x=0;
            vector<int> v=queries[i];
            for(int j=v[0];j<=v[1];j++){
                x=x^arr[j];
            }
            ans.push_back(x);
        }

        return ans;
        
    }
};