class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = -1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low]<=nums[mid]){//left half sorted
                // is it exited in left
                if(target>=nums[low] && target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                // is it ecited in right
                if(target>=nums[mid] && target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};