class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        //make set of wordlist for efficient Search for case1, for exact match
        unordered_set<string> s;
        for(int i=0; i<wordlist.size(); i++){
            s.insert(wordlist[i]);
        }
        //unordered_map of wordlist {all in lower, original}; but insert only when u not find, as we need only first match
        unordered_map<string, string> m2;
        for(int i=0; i<wordlist.size(); i++){
            string key = wordlist[i];
            string value = wordlist[i];
            for (int j = 0; j < key.size(); j++) {
                key[j] = tolower(key[j]);  
            }

            if(m2.find(key) == m2.end()) m2[key] = value;
        }
        ////unordered_map of wordlist {all vowel replace with *, original}; but insert only when u not find, as we need only first match
        unordered_map<string, string> m3;
        for(int i=0; i<wordlist.size(); i++){
            string key = wordlist[i];
            string value = wordlist[i];

            for (int j = 0; j < key.size(); j++) {
                key[j] = tolower(key[j]);  
            }

            for (int j = 0; j < key.size(); j++) {
                if(key[j] == 'a' || key[j] == 'e' || key[j] == 'i' || key[j] == 'o' || key[j] == 'u'){
                    key[j] = '*';  
                }
            }
            
            if(m3.find(key) == m3.end()) m3[key] = value;
        }



        for(int i=0; i<queries.size(); i++){
            //for case 1:
            string temp = queries[i];
            //for case 2: convert to lower case
            string lower = temp;
            for (int j = 0; j < lower.size(); j++) {
                lower[j] = tolower(lower[j]);  
            }
            //for case 3: replace all vowels with '*'
            string vowelErr = lower;
            for (int j = 0; j < vowelErr.size(); j++) {
                if(vowelErr[j] == 'a' || vowelErr[j] == 'e' || vowelErr[j] == 'i' || vowelErr[j] == 'o' || vowelErr[j] == 'u'){
                    vowelErr[j] = '*';
                }
            }


            //case1. exact match
            if(s.find(temp) != s.end()){
                ans.push_back(temp); //exact same then we inserted temp
            }else if(m2.find(lower)!=m2.end()){
                ans.push_back(m2[lower]);
            }else if(m3.find(vowelErr)!=m3.end()){
                ans.push_back(m3[vowelErr]);
            }
            else{
                ans.push_back("");
            }
        }

        return ans;
    }
};