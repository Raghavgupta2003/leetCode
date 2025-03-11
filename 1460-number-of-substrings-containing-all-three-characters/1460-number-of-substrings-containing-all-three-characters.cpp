class Solution {
public: 
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> lastOccIdx = {-1, -1, -1};
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a') lastOccIdx[0] = i;
            else  if(s[i] == 'b') lastOccIdx[1] = i;
            else  if(s[i] == 'c') lastOccIdx[2] = i;
            // when ever we get a,b,c
            //throgh min(lastOccIdx[0], min(lastOccIdx[1], lastOccIdx[2])
            // we get substring before it which invole curr substring.
            if(lastOccIdx[0]!=-1 && lastOccIdx[1]!=-1 && lastOccIdx[2]!=-1){
                ans += 1 + min(lastOccIdx[0], min(lastOccIdx[1], lastOccIdx[2]));
            }

        }

        return ans;
    }
};