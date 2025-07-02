class Solution {
public:
    // void helper(int i, set<vector<int>>& ans, vector<int>& help, vector<int>& nums){
    //     if(i>= nums.size()){
    //         ans.insert(help);
    //         return;
    //     }
        
    //     //pick
    //     help.push_back(nums[i]);
    //     helper(i+1, ans, help, nums);
    //     help.pop_back();

    //     //not pick
    //     helper(i+1, ans, help, nums);
    // }

     void helper(int i, vector<vector<int>>& ans, vector<int>& help, vector<int>& nums){
            
        ans.push_back(help);
       
        
        //pick
        for(int index = i; index<nums.size(); index++){
            if(index > i && nums[index] == nums[index-1]) continue;

            help.push_back(nums[index]);
            helper(index+1, ans, help, nums);
            help.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> help;
        helper(0, ans, help, nums);
       
        // sort(ans.begin(), ans.end());
        return ans;
    }
};