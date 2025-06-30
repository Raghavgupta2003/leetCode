class Solution {
public:
    int fxn(int i, vector<int>& nums, int target){
        if(i >= nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        int positive = fxn(i+1, nums, target+nums[i]);

        int negative = fxn(i+1, nums, target-nums[i]);
        return positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return fxn(0, nums, target);
    }
};