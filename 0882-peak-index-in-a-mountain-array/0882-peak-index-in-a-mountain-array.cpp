class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;  

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] < nums[mid+1]){ //right is increasing
                low = mid+1; //right search
            }
            else if(nums[mid] > nums[mid+1]){ //right is decreasing
                high = mid-1; //left search
            }
        }

        return -1;
    }
};