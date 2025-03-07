class Solution {
public:
   bool isprime(int n){
    if(n == 1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
   }
    vector<int> closestPrimes(int left, int right) {
        vector<int> v;
        for(int i=left; i<=right ; i++){
            if(isprime(i)){
                v.push_back(i);
            }
        }
      
        int mini = INT_MAX;
        int a = -1;
        int b = -1;
        for(int i=v.size()-2; i>=0; i--){
            int diff = v[i+1]-v[i];
            if(mini >= diff){
                mini = diff;
                a=v[i];
                b=v[i+1];
            }
        }

        return {a,b};
    }
};