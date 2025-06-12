class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max_Dist = abs(nums[0] - nums[n-1]); //handling circular part

        for(int i=1; i<n; i++){
            if(abs(nums[i] - nums[i-1]) > max_Dist){
                max_Dist = abs(nums[i] - nums[i-1]);
            }
        }

        return max_Dist;
    }
};