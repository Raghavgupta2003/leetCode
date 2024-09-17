class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(5,0);  //a,e,i,o,u
        string curstate="00000";
        unordered_map<string,int> m;
        m[curstate]=-1;  
        int max_length = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') v[0]=(v[0]+1)%2;  // if(v[0]==0) v[0]=1
            if(s[i]=='e') v[1]=(v[1]+1)%2;  // if(v[0]==1) v[0]=0
            if(s[i]=='i') v[2]=(v[2]+1)%2;;
            if(s[i]=='o') v[3]=(v[3]+1)%2;;
            if(s[i]=='u') v[4]=(v[4]+1)%2;;

            for (int j = 0; j < 5; j++) {
                curstate[j] = v[j] ? '1' : '0';
            }
           
            if(m.find(curstate)!=m.end()){
               max_length =  max(max_length,i-m[curstate]);
            }
            else{
                m[curstate] = i;
            }
        }
        return max_length;
    }
};