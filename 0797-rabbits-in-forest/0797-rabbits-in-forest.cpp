class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for(int i=0; i<answers.size(); i++){
            m[answers[i]]++;
        }
        int ans = 0;
        for(auto it : m){
            int numberofgroup = 0;
            if(it.second % (it.first+1) == 0) numberofgroup = it.second / (it.first+1);
            else  numberofgroup = (it.second / (it.first+1)) + 1;

            ans += numberofgroup * (it.first + 1);
            //each group has answer[i] + 1 rabits
            //main task is to find number of rabbits
        }

        return ans;
    }
};