class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //this question can easily understable by considering
        //longest subarray conataining atmost one 0;
        //Similar Question : Maximum Consecutive ONE's
        int n = nums.size();
        int cnt0 = 0;
        int MaxLength = 0; 
        int i=0;
        int j=0;

        while(i<n){
            if(nums[i] == 0)  cnt0++;

            while(cnt0 > 1 && j<=i){
                if(nums[j] == 0) cnt0--;

                j++;
            } 
            
            MaxLength = max(MaxLength, (i-j+1)-cnt0); //cnt0 is delete element
            i++;
        }

        if(MaxLength == nums.size()){
            // means no zero
            //but we have to delete a elenment
            return nums.size()-1;
        }
        return MaxLength;
    }
};