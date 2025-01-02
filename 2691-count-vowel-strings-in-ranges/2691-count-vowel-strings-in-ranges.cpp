class Solution {
public:
    int isvowel(string s){
        int n = s.size()-1;
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
            if(s[n]=='a' || s[n]=='e' || s[n]=='i' || s[n]=='o' || s[n]=='u'){
                return 1;
            }
        }
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n+1,0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + isvowel(words[i]);
        }


        for(int i=0;i<pre.size();i++){
            cout<<pre[i]<<" ";
        }
        
        cout<<endl;

        vector<int> ans;
        for(int i=0; i< queries.size(); i++){
           int m = queries[i][0];
           int n = queries[i][1];
           cout<<m<<" "<<n<<endl;

           ans.push_back(pre[n+1]-pre[m]);

        }

        return ans;
    }
};