class Solution {
public:
    bool dfs(int node,  vector<int>& visited, vector<int>& pathvisited, vector<vector<int>>& graph, vector<int>& safenode){

        visited[node] = 1;
        pathvisited[node] = 1;

        for(auto it : graph[node]){
            if(!visited[it]){
                if(dfs(it, visited, pathvisited, graph, safenode) == true){
                    //true means cycle detected
                    safenode[node] = 0;
                    return true;
                }
            }
            else{ 
                //already visited
                //check is it is visited on same path..?
                if(pathvisited[it] == 1){ //cycle found
                    safenode[node] = 0;
                    return true;
                }
            }

        }

        // if no cycle found
        //if come back to our path
        //mark path as unvisited
        //and mark safe node as 1

        pathvisited[node] = 0;
        safenode[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); // NUMBER OF NODES

        vector<int> visited(n, 0);
        vector<int> pathvisited(n, 0);
        vector<int> safenode(n, 0);

        for(int i=0; i<n; i++){
            if(!visited[i])
            dfs(i, visited, pathvisited, graph, safenode);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(safenode[i]) ans.push_back(i);
        }

        return ans;
    }
};