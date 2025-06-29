class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(int i=0; i<wordList.size(); i++){
            s.insert(wordList[i]);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); //{beginword, steps}
        s.erase(beginWord); //if present

        while(q.size() > 0){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(int j=0; j<26; j++){
                    word[i] = (char)(j + 'a');

                    if(s.find(word) != s.end()){
                        q.push({word, steps+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }

        }

        return 0;
    }
};