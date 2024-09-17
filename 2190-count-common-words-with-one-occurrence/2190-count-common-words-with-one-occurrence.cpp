class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1;
        for(int i=0;i<words1.size();i++){
            m1[words1[i]]++;
        }
        unordered_map<string,int> m2;
        for(int i=0;i<words2.size();i++){
            m2[words2[i]]++;
        }
        int cnt = 0;
        for(auto pair:m1){
            if(pair.second==1){
                if(m2.find(pair.first)!=m2.end()){
                    for(auto p:m2){
                        if(p.first==pair.first &&  p.second==1){
                            cnt++;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};