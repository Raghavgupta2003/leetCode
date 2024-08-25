class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length()+1;

        vector<int> preN(n);
        preN[0]=0;  //No before first index is 0
        for(int i=1;i<n;i++){
            if(customers[i-1]=='N')
            preN[i]=preN[i-1] + 1;
            else
            preN[i]=preN[i-1] + 0;

        }

        vector<int> sufY(n);
        sufY[n-1]=0;  //yes after last idx is 0
        for(int i=n-2;i>=0;i--){
            if(customers[i]=='Y')
            sufY[i]=sufY[i+1] + 1;
            else
            sufY[i]=sufY[i+1] + 0;

        }

        
        for(int i=0;i<n;i++){
            preN[i]+=sufY[i];
        } 

        int min = preN[0];
        
        for(int i=0;i<n;i++){
           if(preN[i]<min){
                min=preN[i];
            }
        } 
        for(int i=0;i<n;i++){
            if(preN[i]==min) return i;
        }
        return 30;
        
    }
};