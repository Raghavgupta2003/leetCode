class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        vector<int> v(n); //sufix sum array
        v[n-1] = sat[n-1];
        for(int i=n-2;i>=0;i--){
            v[i]=v[i+1]+sat[i];
        }
        int idx=-1;
        vector<int> helper;
        for(int i=0;i<n;i++){
            if(v[i]>0)
            helper.push_back(sat[i]);
        }


        int ans=0;
        for(int i=0;i<helper.size();i++){
            ans+=(helper[i]*(i+1));
        }
        // for(int i=0;i<helper.size();i++){
        //     cout<<helper[i]<<" ";
        // }
        return ans;
        
    }
};