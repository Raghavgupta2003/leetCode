class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;

        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        int cnt = 0;
        bool hasMid = false;
        for(auto& it : m){
            string w = it.first;
            string rev = "";
            rev = string() + w[1] + w[0];

            if(rev == it.first){//aa, bb, vv
                cnt += (it.second/2) * 4; // we use x/2 to remove 1 string in case of odd;
                if(it.second %2 == 1){
                    hasMid = true; //leftover to add in b/w
                }
                it.second = 0; 
            }
            else if(m.find(rev) != m.end()){
                cnt += min(it.second, m[rev])*4; //pairs

                it.second = 0;
                m[rev] = 0;
            }
        }

        if(hasMid) cnt+=2;

        return cnt;
    }
};