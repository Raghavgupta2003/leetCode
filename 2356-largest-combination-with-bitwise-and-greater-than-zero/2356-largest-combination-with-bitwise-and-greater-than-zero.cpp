class Solution {
public:
    void decToBinary(int n,vector<int> &v)
    {
        int i=0;
        while (n > 0) {
            int ans = n % 2;
            if(ans == 1) v[i]++;
            n = n / 2;
            i++;
        }  
    }
    int largestCombination(vector<int>& candidates) {
        vector<int> v(24,0);
        for(int i=0;i<candidates.size();i++){
            decToBinary(candidates[i],v);

        }

        sort(v.begin(),v.end());
        
        return v[v.size()-1];
    }
};