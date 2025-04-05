class Solution {
public:
    bool dfs(int node, vector<int>& visited, int color, vector<vector<int>>& graph){
        visited[node] = color;

        for(auto it : graph[node]){
            if(visited[it] == -1){ //not visited
                if(!dfs(it, visited, !color, graph)) return false;
            }
            else{
                // already visited
                // check if it has same color..?
                // if same color NOT a bipartite which means return false;
                if(visited[it] == color){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); //number of nodes

        //in visited array we store color as 0 and 1 
        vector<int> visited(n, -1);
        int color = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == -1){ //not visited 
                if(!dfs(i, visited, color, graph)) return false;
            }
        }

        return true;
    }
};