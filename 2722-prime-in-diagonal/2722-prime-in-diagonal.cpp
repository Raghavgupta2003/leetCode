class Solution {
public:
    bool isprime(int n){
        int c=0;
        if(n<2) return false;  
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) c++;
        }
        if(c==0) return true;
        else return false;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int row = nums.size();
        int column = nums[0].size();
        vector<int> v;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(i==j || (i+j)==row-1){
                    if(isprime(nums[i][j])){
                        v.push_back(nums[i][j]);
                    }
                }
            }
        }
        if(v.size()==0) return 0;
        sort(v.begin(),v.end());
        return v[v.size()-1];
        
    }
};