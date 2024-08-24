class Solution {
public:
    const int MOD = 1e9 + 7;
    unsigned long long fact(long long n){
        if(n==1) return 1;
        return n*fact(n-1)%MOD;
    }
    
    int isprime(vector<int> &v){
        int n=v.size()-1;
        for(int i=2;i*i<=n;i++){
            if(v[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=0;
                }
            }
        }
        int c=0;
        for(int i=2;i<=n;i++){
            if(v[i]) c++;
        }
        return c;
    }
    int numPrimeArrangements(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        vector<int> v(n+1,1);
        long long primep = isprime(v);
        long long compositep = n-primep;
        long long ans = fact(primep) * fact(compositep);

        return ans%MOD;

    }
};