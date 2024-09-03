class Solution {
public:
    int getLucky(string s, int k) {
        int x=0;
        for(int i=0;i<s.length();i++){
            int ch = s[i]-'a'+1;
            int ach=0;
            while(ch>0){
                int temp = ch%10;
                ach+=temp;
                ch/=10;
            }
            x+=ach;
        }

        cout<<x<<endl;
    
       for(int i=1;i<k;i++){ //k-1 operations
        int ans =0;
         while(x>0){
            int temp = x%10;
            ans+=temp;
            x/=10;
        }
        x=ans;
       }
       return x;
       
    }
};