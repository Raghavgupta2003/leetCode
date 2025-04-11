class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            string x = to_string(i);
            if(x.size()%2 ==0){ //checking only for even size
                int j=0;
                int k=x.size()-1;
                int sum1 = 0;
                int sum2 = 0;
                while(j<k){
                    sum1+=x[j];
                    sum2+=x[k];
                    j++;
                    k--;
                }
                if(sum1 == sum2){
                    cout<<x<<" ";
                    cnt++;
                } 
            }           
        }
        return cnt;
    }
};