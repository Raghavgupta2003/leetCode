class Solution {
public:
    int findMin(vector<int>& nums) {
        //-------Brute force-------
        int minimum = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(minimum > nums[i]) minimum = nums[i];
        }
        return minimum;
    }
};