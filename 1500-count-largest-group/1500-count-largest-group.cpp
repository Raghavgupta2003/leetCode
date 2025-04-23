class Solution {
public:
    int SUM(int n){
        int x = 0;
        while(n){
            x+=(n % 10);
            n/=10;
        }
        // cout<<x<<endl;
        return x;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for(int i=1; i<=n; i++){
            int sum = SUM(i);
            m[sum]++;
        }

        //count the frquency of frequency of sum
        unordered_map<int, int> freq;
        for(auto it: m){
            freq[it.second]++;
        }
        //maximum
        int maxi = 0;
        for(auto it: freq){
            maxi = max(maxi, it.first);
        }

        return freq[maxi];
    }
};