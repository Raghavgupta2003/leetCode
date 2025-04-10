class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        //for easy search and removal to avoid again again reacing same element
        //result in infinite loop
        for(int i=0; i<wordList.size(); i++){
            s.insert(wordList[i]);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(q.size() > 0){
            string cur = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(cur == endWord) return dist; //we got endWord

            //replacing characters of cur by all 26 letters
            for(int i=0; i<cur.size(); i++){
                char original = cur[i];
                for(int j=0; j<26; j++){
                    cur[i] = 'a'+j; //replaced to get next word
                    if(s.find(cur) != s.end()){
                        q.push({cur, dist + 1});
                        s.erase(cur);
                    }
                }
                cur[i] = original; //again replaced by original to get same word.
            }
        }
        return 0;
    }
};