class Solution {
public:
    void isprime(vector<int> &v){
        int n=v.size()-1; //because size of array = n+1;
        v[0]=0;
        v[1]=0;
        for(int i=2;i*i<=n;i++){
            if(v[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=0;
                }
            }
        }
    
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> v(n+1,1);
        isprime(v);

        vector<vector<int>> ans;
        for(int i=2;i<=n/2;i++){
            if(v[i] && v[n-i]){
                    vector<int> x;
                    x.push_back(i);
                    x.push_back(n-i);
                    ans.push_back(x);
             }
        }
           
        return ans;
    }
};