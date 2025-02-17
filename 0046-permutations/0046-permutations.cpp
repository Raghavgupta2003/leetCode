class Solution {
public:
    void permutations(vector<int>& arr, vector<vector<int>> &ans, vector<int>& v,  unordered_map<int, int> &m){
        if(v.size()== arr.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0; i<arr.size(); i++){
            if(m.find(arr[i]) == m.end()){
                v.push_back(arr[i]);
                m[arr[i]] = 1;
                permutations(arr, ans, v, m);
                m.erase(arr[i]);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> m;
        permutations(nums, ans, v, m);
        return ans;
    }
};