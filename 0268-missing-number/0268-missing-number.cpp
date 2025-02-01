class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low + ((high - low)/2);
            if(nums[mid] == mid){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        if(ans == -1) return nums[nums.size()-1]+1;
        return ans;
    }
};