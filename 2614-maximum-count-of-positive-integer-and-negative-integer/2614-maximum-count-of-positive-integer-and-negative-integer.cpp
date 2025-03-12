// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size()-1;
//         int lastNegativeIdx = -1;
//         while(low<=high){
//             int mid = low + (high-low)/2;

//             if(nums[mid] < 0){
//                 if(mid == nums.size()-1){
//                     lastNegativeIdx = mid;
//                     break;
//                 }
//                 if(mid!=nums.size()-1 && nums[mid+1] >=0){
//                     lastNegativeIdx = mid;
//                     break;
//                 }
//                 else low = mid + 1;
//             }
//             else if(nums[mid]>=0){
//                 high = mid-1;
//             }
            
//         }
//         cout<<lastNegativeIdx<<" ";
//         long long neg = lastNegativeIdx + 1;

//        //-----------------------------------------------

//         low = 0;
//         high = nums.size()-1;
//         long long firstPositiveIdx = -1;
//         while(low<=high){
//             int mid = low + (high-low)/2;

//             if(nums[mid] > 0){
//                 if(mid == 0){
//                     firstPositiveIdx = mid;
//                     break;
//                 }
//                 if(mid!=0 && nums[mid-1] <=0){
//                     firstPositiveIdx = mid;
//                     break;
//                 }
//                 else high = mid - 1;
//             }
//             else if(nums[mid]<=0){
//                 low = mid+1;
//             }
            
//         }
//         cout<<firstPositiveIdx<<" ";
//         if(firstPositiveIdx == -1) return neg;
//         long long pos = nums.size() - (firstPositiveIdx);
//         cout<<pos;
//         //return pos;

//         return max(neg, pos);

        
//     }
// };


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // store first non negative idx;
        // elements previous to it are negative
        // increase nonnegative index by count of zero.
        // elements after updated index are positive.

        int low = 0;
        int high = nums.size()-1;
        int nonNegativeElement = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= 0){
                nonNegativeElement = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        cout<<nonNegativeElement<<endl;
        // All Positive
        if(nonNegativeElement == -1) return nums.size();

        int pos = nonNegativeElement;
        while(nonNegativeElement<nums.size() && nums[nonNegativeElement] == 0){
            nonNegativeElement++;
        }
        cout<<nonNegativeElement<<endl;
        int neg = nums.size()-nonNegativeElement;

        return max(pos,neg);
    }
};