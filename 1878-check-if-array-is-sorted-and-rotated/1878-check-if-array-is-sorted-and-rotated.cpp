class Solution {
public:
    bool check(vector<int>& nums) {
        int position = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                position = i;
            }
        }
        vector<int> v= nums;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=v[(i+position)%nums.size()]) return false;
        }
        return true;        
    }
};
