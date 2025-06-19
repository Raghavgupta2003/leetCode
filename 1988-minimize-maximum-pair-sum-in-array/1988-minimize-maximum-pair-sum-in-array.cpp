class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i=0; 
        int j=nums.size()-1;
        
        int maxSum = INT_MIN;
        while(i<=j){
            maxSum = max(maxSum, nums[i]+nums[j]);
            i++;
            j--;
        }

        return maxSum;
    }
};