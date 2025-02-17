class Solution {
public:
    //-----------------Duplicates in INPUT------------------
    void Tiles(int idx, string &tiles,vector<string> &ans, string str){

        cout<<str<<" ";
        ans.push_back(str);
        for(int i=idx; i<tiles.size();i++){
            if(idx < i && tiles[i]==tiles[i-1]) continue;
            //pick
            Tiles(i + 1, tiles, ans, str + tiles[i]);
        }
    }

    int fact(int n){
        int fact = 1;
        for(int i=1; i<=n;i++){
            fact*= i;
        }
        return fact;
    }

    int permutations(unordered_map<char,int> m, string str){
        for(int i=0; i<str.size(); i++){
            m[str[i]]++;
        }
        int ans = 1;
        for(auto pair : m){
            if(pair.second > 1){
                ans *= fact(pair.second);
            }
        }
        return fact(str.size())/ans;

    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<string> ans;
        string str = "";
        Tiles(0,tiles, ans, str);
        int answer = 0;
        for(int i=0; i<ans.size(); i++){
            unordered_map<char, int> m;
            answer += permutations(m, ans[i]);
        }

        return answer-1;
    }
};