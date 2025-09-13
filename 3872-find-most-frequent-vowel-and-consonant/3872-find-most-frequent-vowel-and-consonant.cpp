class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        int maxvowel = 0;
        int maxcons = 0;
        for(auto it: m){
            char ch = it.first;
            if(ch == 'a' || ch=='e' || ch == 'i' || ch=='o' || ch == 'u'){
                maxvowel = max(maxvowel, it.second);
            }else{
                maxcons = max(maxcons, it.second);
            }
        }

        return maxvowel + maxcons;
    }
};