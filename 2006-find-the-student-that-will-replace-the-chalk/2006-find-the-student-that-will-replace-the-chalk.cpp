class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n= chalk.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        while(k >= sum) {
            k=k-sum;
        }
        cout<<k;
        int idx=-1;
        for(int i=0;i<n;i++){
           
            if(k<chalk[i]){
                idx=i;
                break;
            }
            k=k-chalk[i];
        }

        if (idx==-1) return 0;
        return idx;
        
    }
};