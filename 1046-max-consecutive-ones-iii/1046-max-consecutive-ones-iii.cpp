class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // // ***Can we understand this question as
        // // Longest SubArray containing 0 <= k***
        // int n = nums.size();
        // int MaxLen = INT_MIN;
        // int cnt0 = 0; 
        // int j = 0;
        // for(int i=0; i<n; i++){
        //     if(nums[i] == 0){
        //         cnt0++;
        //     }

        //     while(cnt0 > k && j<=i){
        //         if(nums[j]==0)cnt0--;
        //         j++;
        //     }

        //     if(cnt0 <= k) MaxLen = max(MaxLen, i-j+1);
        // }
        // return MaxLen;

        //-----------------------------------------------

        int n = nums.size();
        int MaxLen = INT_MIN;
        int cnt0 = 0; 
        int i=0;
        int j = 0;
        while(i<n){
            if(nums[i] == 0){
                cnt0++;
            }

            while(cnt0 > k){
                if(nums[j]==0)cnt0--;
                j++;
            }

            MaxLen = max(MaxLen, i-j+1);
            i++;
        }
        return MaxLen;


    }
};