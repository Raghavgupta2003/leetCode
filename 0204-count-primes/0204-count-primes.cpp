class Solution {
public:
    void isprime(vector<int> &v){
        // v[0]=0;
        // v[1]=0;
        int n=v.size();
        for(int i=2;i*i<n;i++){
            if(v[i]==1){
                for(int j=i*i;j<n;j+=i){
                    v[j]=0;
                }
            }
        }
    }
    int countPrimes(int n) {
        vector<int>pre(n,1);
        // pre[0]=0;
        // pre[1]=0;
        isprime(pre);
        int c=0;
        for(int i=2;i<n;i++){
            if(pre[i]==1) c++;
        }

        return c;

    }
};