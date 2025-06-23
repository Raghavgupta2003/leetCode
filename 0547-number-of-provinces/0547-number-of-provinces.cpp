class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
      visited[node] = 1;

      for(auto it : adj[node]){
        if(!visited[it]){
          dfs(it, adj, visited);
        }
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1, vector<int>(0)); //since Nodes are starting from 1

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j] == 1 && i<j){
                    adj[i+1].push_back(j+1);

                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<int> visited(n+1, 0);
        int cnt = 0;

        for(int i=1; i<n+1; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }
};