class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        //base case
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        //logic
        int low = 1;
        int high = n-2;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] < nums[mid+1]){ //right is increasing
                low = mid+1; //move to right
            }
            else{ //right is decreaing 
                high = mid-1; //move to left
            }
            
        }

        return -1;
    }
};