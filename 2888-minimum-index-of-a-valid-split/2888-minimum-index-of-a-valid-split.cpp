class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for(auto it : nums){
            m[it]++;
        }
        int dominantFreq = 0;
        int dominantEle = 0;
        for(auto pair : m){
            if(pair.second > dominantFreq){
                dominantFreq = pair.second;
                dominantEle = pair.first;
            }
        }

       // since dominant Element = element which appear more than the size/2
       // Now we will iterate through arr and check this condition
       int freqOfFirstSplit = 0;
       int freqOfSecondSplit = 0;
       for(int i=0; i<nums.size(); i++){
        if(nums[i] == dominantEle){
            freqOfFirstSplit = freqOfFirstSplit + 1;
            freqOfSecondSplit = dominantFreq - freqOfFirstSplit;  
        }
        int n1 = i+1; //size of first split
        int n2 = nums.size()-i-1; // size of second split

        //checking if x is dominant or not in both parts
        
        if( freqOfFirstSplit > n1/2 &&  freqOfSecondSplit > n2/2){
            return i;
        }

       }
        return -1;
    }
};