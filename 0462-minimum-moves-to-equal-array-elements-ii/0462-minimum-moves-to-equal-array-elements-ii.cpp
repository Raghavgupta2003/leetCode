class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int targetEle = nums[(nums.size()/2)]; // mid element

        // moves = +1 or -1
        // means total moves = abs[element - midelement] -> these much increaments can be done to make element equal to midelement(target);
        
        int totalMoves = 0;
        for(int i=0; i<nums.size(); i++){
            totalMoves += abs(targetEle - nums[i]);
        }

        return totalMoves;

        //---for better understanding check (2033. Minimum Operations to Make a Uni-Value Grid), i have explained in code part-------
        
    }
};