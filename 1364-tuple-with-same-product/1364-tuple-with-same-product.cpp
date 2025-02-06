
// class Solution {
// public:
//     long long fact(int n){
//         long long fact = 1;
//         for(int i=1;i<=n;i++){
//             fact*=i;
//         }
//         return fact;
//     }
//     int combination(int n,int r){
//         return (fact(n)/(fact(n-r) * fact(r)));
//     }

//     int tupleSameProduct(vector<int>& nums) {
//         vector<int> pdt;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1; j<nums.size();j++){
//                 pdt.push_back(nums[i] * nums[j]);
//             }
//         }

    
//         map<int,int> m;
//         for(int i=0; i<pdt.size(); i++){
//             cout<<pdt[i]<<" ";
//             m[pdt[i]]++;
//         }
//         int ans = 0;
//         for(auto it : m){
//             cout<<it.first<<" "<<it.second<<endl;
//             if(it.second == 2) ans += 8;
//             if(it.second > 2) ans += (combination(it.second,2) * 8);
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int combination(int n){
        return ((n * (n-1))/2);
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                int pdt = nums[i] * nums[j];
                // cout<<pdt<<" ";
                m[pdt]++;
            }
        }
        int ans = 0;
        for(auto it : m){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second == 2) ans += 8;
            if(it.second > 2) ans += (combination(it.second) * 8);
        }

        return ans;
    }
};