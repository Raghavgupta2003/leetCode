// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {
//         // we have basecase for size = 0, 1, 2
//         if(nums.size() == 0) return 0; //already distint;
//         if(nums.size() == 1) return 0;
//         if(nums.size() == 2){
//             if(nums[0] == nums[1]) return 1;
//             return 0;
//         }
//         int cnt = 0;
//         int i=0;
//         for(i=0; i<nums.size(); i+=3){
//             set<int> s;
//             for(int j=i; j<nums.size(); j++){
//                 s.insert(nums[j]);
//             }
//             if(s.size() == nums.size()-i) return cnt;
//             cnt++;
//         }
//         return cnt;

//         //we use set and nested loop to remove duplicate
//         //we increment i by 3.
//     }
// };


//------------------------------------------------------------------

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       // we use hashmap and store digits from end of array.
       //if frquency of any element become 2 or greater
       //break the loop then we find number of operation by value of i;

        unordered_map<int, int> m;
        int i;
       for(i=nums.size()-1; i>=0; i--){
             m[nums[i]]++;
            if(m[nums[i]] >= 2) break;
       }
       cout<<i;

       if(i == -1) return 0; //no duplicate found
       if((i+1)%3 == 0) return (i+1)/3;
       
       return ((i+1)/3)+1;
    }
};