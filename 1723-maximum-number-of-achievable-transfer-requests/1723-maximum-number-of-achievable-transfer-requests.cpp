class Solution {
public:
    int maxiRequests = 0;
    void maxRequests(int index, int count, vector<int>& buildings, vector<vector<int>>& requests){
        if(index >= requests.size()){
            for(int i=0; i<buildings.size(); i++){
                if(buildings[i]!=0) return;
            }

            //if all zeroes
            maxiRequests = max(maxiRequests, count);
            return;
        }
        int from = requests[index][0];
        int to = requests[index][1];
        
        //pick
        buildings[from]--;
        buildings[to]++;

        maxRequests(index+1, count+1, buildings, requests);

        buildings[from]++;
        buildings[to]--;

        //not pick
        maxRequests(index+1, count, buildings, requests);
    } 
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildings(n, 0);

        maxRequests(0, 0, buildings, requests);


        return maxiRequests;
    }
};