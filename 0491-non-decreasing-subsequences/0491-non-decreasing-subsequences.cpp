class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& help, set<vector<int>>& ans){
        if(i >= nums.size()){
            if(help.size() >= 2) ans.insert(help);
            return;
        }

        //pick
        if(help.size() == 0 || help.back() <= nums[i]){
            help.push_back(nums[i]);
            helper(i+1, nums, help, ans);
            help.pop_back();
        }

        // while(i+1 < nums.size() && nums[i] == nums[i+1]) continue; //duplicate remove

        //non pick
         helper(i+1, nums, help, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> ans;
        vector<int> help;

        helper(0, nums, help, ans);

        vector<vector<int>> arr;
        arr.assign(ans.begin(), ans.end());
        return arr;
         
    }
};