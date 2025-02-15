class Solution {
public:
    void subset(int idx, vector<int>& arr, vector<vector<int>> &ans, vector<int> &v ){
        
        ans.push_back(v);

        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            v.push_back(arr[i]);
            subset(i+1, arr, ans, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        subset(0, nums, ans, v);
        return ans;
    }
};