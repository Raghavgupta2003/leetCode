class Solution {
public:
    //***In this question duplicate exists****
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }

            // leftsorted
           else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<= nums[mid]){
                    high = mid-1; //removing unsorted part
                }
                else{
                    low = mid+1;
                }
            }else{
                //right sorted
                if(target>=nums[mid] && target<= nums[high]){
                    low = mid+1; //removing unsorted part
                }
                else{
                    high = mid-1;
                }
            }
        }

        return false;
    }
};