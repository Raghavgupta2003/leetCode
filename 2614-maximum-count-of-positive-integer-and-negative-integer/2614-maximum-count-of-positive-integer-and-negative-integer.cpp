class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int lastNegativeIdx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] < 0){
                if(mid == nums.size()-1){
                    lastNegativeIdx = mid;
                    break;
                }
                if(mid!=nums.size()-1 && nums[mid+1] >=0){
                    lastNegativeIdx = mid;
                    break;
                }
                else low = mid + 1;
            }
            else if(nums[mid]>=0){
                high = mid-1;
            }
            
        }
        cout<<lastNegativeIdx<<" ";
        long long neg = lastNegativeIdx + 1;

       //-----------------------------------------------

        low = 0;
        high = nums.size()-1;
        long long firstPositiveIdx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] > 0){
                if(mid == 0){
                    firstPositiveIdx = mid;
                    break;
                }
                if(mid!=0 && nums[mid-1] <=0){
                    firstPositiveIdx = mid;
                    break;
                }
                else high = mid - 1;
            }
            else if(nums[mid]<=0){
                low = mid+1;
            }
            
        }
        cout<<firstPositiveIdx<<" ";
        if(firstPositiveIdx == -1) return neg;
        long long pos = nums.size() - (firstPositiveIdx);
        cout<<pos;
        //return pos;

        return max(neg, pos);

        
    }
};