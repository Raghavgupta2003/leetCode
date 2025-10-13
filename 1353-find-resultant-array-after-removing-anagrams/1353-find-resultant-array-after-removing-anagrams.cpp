class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if (words.empty()) return ans;
        string prev =  words[0];
        string sortPrev = words[0];
        sort(sortPrev.begin(), sortPrev.end());
        ans.push_back(prev);
        for(int i=1; i<words.size(); i++){
            string curr = words[i];
            sort(curr.begin(), curr.end());
            if(curr != sortPrev){
                ans.push_back(words[i]);
                sortPrev = curr;
            }
        }


        return ans;
    }
};