class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = 0;
        int ones = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
            else{
                ones = 0;
            }

            if(max1<ones) max1 = ones;
        }
        return max1;
    }
};