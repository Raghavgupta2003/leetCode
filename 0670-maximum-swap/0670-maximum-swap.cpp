class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());

        vector<int> maxR(v.size());   //stores index of max element to right 
        maxR[v.size()-1] = v.size()-1;
        for(int i=maxR.size()-2;i>=0;i--){
            int maxidx =maxR[i+1];
            int maxele = v[maxidx];
            if(v[i]>maxele){
                maxidx = i;
            }
            maxR[i] = maxidx;
        }
        for(int i=0;i< maxR.size();i++){
            int maxidx = maxR[i];
            int maxele = v[maxidx];

            if(v[i]<maxele){
                swap(v[i],v[maxidx]);
                break;
            }
            
        }

        int n=v.size();
        int ans = 0;
        for(int i =0;i<v.size();i++){
            ans+= v[i]*pow(10,n-1);
            n--;
        }
        return ans;
    }
};