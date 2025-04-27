class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=2;
        int cnt = 0;
        while(j < nums.size()){
            if(nums[i] + nums[j] == (nums[i+1])/2.0){
                cnt++;
            }
            i++;
            j++;
        }
        return cnt;
    }
};