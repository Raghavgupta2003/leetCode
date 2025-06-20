class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int minimum = nums[0];
        
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                minimum = min(minimum, nums[low]);
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]){ //left sorted
                minimum = min(minimum, nums[low]);
                low = mid+1;
            }
            else{//right sorted
                minimum = min(minimum, nums[mid]);;
                high = mid-1;
            }
        }

        return minimum;
    }
};