// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) {
//         int count = 0;
//         for(int i=0; i<nums.size()-1;i++){
//             for(int j=i+1; j<nums.size();j++){
//                 if((j-i) != (nums[j]-nums[i])){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


// Above solution give TLE.
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // Notice that (j - i != nums[j] - nums[i]) is the same as (nums[i] - i != nums[j] - j).
        // good pair = (nums[i]-i  ==  nums[j]-j)
        int n = nums.size();
        // long long totalPairs =  (n*(n-1))/2;  //nC2
        long long totalPairs =  (1LL * n * (n-1))/2;  //1LL is used to store large value in long long
        map<int,int> m;
        for(int i=0; i<nums.size();i++){
            nums[i] = nums[i]-i;
            m[nums[i]]++;
        }

        long long GoodPairs = 0;
        for(auto it : m){
            if(it.second >= 2){
                int x = it.second;
                GoodPairs += (1LL * x * (x-1))/2; //nC2
            }
        }


        return (totalPairs - GoodPairs);
    }
};