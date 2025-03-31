class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairsum; // to store all possible pair
        for(int i=1; i<n; i++){
            pairsum.push_back(weights[i-1] + weights[i]);
        }

        sort(pairsum.begin(), pairsum.end());

        int pair = k-1;

        long long maxsum = 0;
        long long minsum = 0;
        int i=0;
        int j=pairsum.size()-1;

        while(pair){
            minsum += pairsum[i];
            i++;
            maxsum += pairsum[j];
            j--;

            pair--;

        }

        return maxsum - minsum;
    }
};