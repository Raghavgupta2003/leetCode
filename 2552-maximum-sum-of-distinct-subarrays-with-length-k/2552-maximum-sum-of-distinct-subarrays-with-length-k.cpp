// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         //Brute Force
//         int max = 0;
//         for(int i=0;i<nums.size()-k+1;i++){
//             int sum = 0;
//             unordered_set<int> s;
//             for(int j=i; j<i+k; j++){
//                 cout<<nums[j]<<" ";
//                 s.insert(nums[j]);
//                 sum+=nums[j];
//             }
//             cout<<endl;
//             if(s.size()==k){
//                 if(max<=sum) max=sum;
//             }
//         }

//         return max;
//     }
// };

//--------------------Approach 2-----------------------

// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int max = 0;
//         unordered_set<int> s; // set is used to check whether the elements are unique or not.
//         int sum = 0;
//         // making first subarray of size k
//         for(int j=0; j<k; j++){
//                 s.insert(nums[j]); 
//                 sum+=nums[j];
//         }
//         if(s.size()==k){
//             if(max<=sum) max=sum;
//         }

//         for(int i=k;i<nums.size();i++){
//             s.erase(nums[i-k]);   //removing first element
//             s.insert(nums[i]);   // adding [previous subarray.size()-1]+1 element
//             sum += nums[i];
//             sum -= nums[i-k];
//             if(s.size()==k){
//                 if(max<=sum) max=sum;
//             }
//         }

//         return max;
//     }
// };



//-----------------------------------------------------------
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> elements;
        long long current_sum = 0;
        long long max_sum = 0;
        int begin = 0;
        
        for (int end = 0; end < n; end++) {
            if (elements.find(nums[end]) == elements.end()) {
                current_sum += nums[end];
                elements.insert(nums[end]);
                
                if (end - begin + 1 == k) {
                    max_sum = max(max_sum, current_sum);
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
            } else {
                while (nums[begin] != nums[end]) {
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }
        
        return max_sum;
    }
};
