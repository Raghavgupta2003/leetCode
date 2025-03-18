class Solution {
public:
    bool isNice(int i, int j, vector<int>& nums){
        int mask = 0;
        for(int k = i; k <= j; k++){
            if((mask & nums[k]) != 0) return false;  //condition met
            mask = mask | nums[k];  // storing whose bits are 1
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int maxi =0;
        while(j<nums.size()){
           if(isNice(i, j, nums) == false){
                i++;
           }
           else{
                maxi = max(maxi, j-i+1);
            }
           j++;
        }

        return maxi;
    }
};
