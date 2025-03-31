class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        //---------BRUTE FORCE-------------

        // int n = arr.size();

        // int cnt = 0;
        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += arr[j];
        //         if(sum % 2 != 0) cnt++;
        //     }
        // }
        // return cnt;

        //------------TRICKY OPTIMISE  (evenPrefixSumCount * oddPrefixSumCount) + oddPrefixSumCount))-------

        // int n = arr.size();
        // vector<int> pre(n);
        // pre[0] = arr[0];

        // for(int i=1; i<n; i++){
        //     pre[i] = arr[i] + pre[i-1];
        // }

        // //counting odd and even prefix sums
        // int oddCount = 0;
        // int evenCount = 0;

        // for(int i=0; i<n; i++){
        //     if(pre[i]%2 == 0) evenCount++;
        //     else oddCount++;
        // }
        // int mod = 1e9 + 7;
        // return ((evenCount * oddCount)%mod + oddCount)%mod;


        //------------------By understanding-----------------


        // now we know:
        // EVENsum + ODDsum = ODDsum
        int mod = (1e9 + 7);

        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];

        for(int i=1; i<n; i++){
            pre[i] = arr[i] + pre[i-1];
        }

        int even = 0;
        int odd = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(pre[i]%2 == 0){ // even + previousODD = ODD
                cnt = (cnt + odd) % mod;
                even++;
            }
            if(pre[i]%2 !=0 ){ //odd + previousEven = Even
                cnt = (cnt + (even+1)) % mod;
                odd++;
            }
        }

      
        return cnt % mod;

        //concept:
        //odd + even = odd
        //even + odd = odd
        //while traversing in prefix sum array, we count odd as well as even SUM
        // when we encounter evenSUM then it can accumulate with all previous ODDSUM to get odd_SUM_subarray 
        // when we encounter oddSUM then it can accumulate with all previous EVENSUM to get odd_SUM_subarray, but in this case ODDSum is also considered as a subarray. so, we initialize even with one.
        // we can also do like (even + 1) when we encounter oddSum, instead of initializing even with 0. 
        
    }
};