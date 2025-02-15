class Solution {
public:
    void helper(int idx, vector<int>& arr, vector<vector<int>>& ans,vector<int> &v){
        if(idx >= arr.size()){
            ans.push_back(v);
            return;
        }

        //pick
        v.push_back(arr[idx]);
        helper(idx+1, arr, ans, v);
        v.pop_back();

        //not pick
        helper(idx+1, arr, ans, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0, nums, ans, v);
        return ans;
    }
};