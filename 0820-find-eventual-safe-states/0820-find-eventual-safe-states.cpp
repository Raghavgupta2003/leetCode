class Solution {
public:
    // bool dfs(int node,  vector<int>& visited, vector<int>& pathvisited, vector<vector<int>>& graph, vector<int>& safenode){

    //     visited[node] = 1;
    //     pathvisited[node] = 1;

    //     for(auto it : graph[node]){
    //         if(!visited[it]){
    //             if(dfs(it, visited, pathvisited, graph, safenode) == true){
    //                 //true means cycle detected
    //                 safenode[node] = 0;
    //                 return true;
    //             }
    //         }
    //         else{ 
    //             //already visited
    //             //check is it is visited on same path..?
    //             if(pathvisited[it] == 1){ //cycle found
    //                 safenode[node] = 0;
    //                 return true;
    //             }
    //         }

    //     }

    //     // if no cycle found
    //     //if come back to our path
    //     //mark path as unvisited
    //     //and mark safe node as 1

    //     pathvisited[node] = 0;
    //     safenode[node] = 1;
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int n = graph.size(); // NUMBER OF NODES

    //     vector<int> visited(n, 0);
    //     vector<int> pathvisited(n, 0);
    //     vector<int> safenode(n, 0);

    //     for(int i=0; i<n; i++){
    //         if(!visited[i])
    //         dfs(i, visited, pathvisited, graph, safenode);
    //     }

    //     vector<int> ans;
    //     for(int i=0; i<n; i++){
    //         if(safenode[i]) ans.push_back(i);
    //     }

    //     return ans;
    // }

    //---------------------------toposort-----------------------

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); // NUMBER OF NODES

        //REVERSING EDGES
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i=0; i<graph.size(); i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }

        //PRINTING REVERSED EDGES TO VERIFY
        // for(int i=0; i<adj.size(); i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        //INDEGREE
        vector<int> indegree(n);
        for(int i=0; i<adj.size(); i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        //INITIALIZING QUEUE
        //PUSHING NODES WHOSE INDEGREE IS 0

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        //INITIALIZING TOPOSORT VECTOR
        vector<int> toposort;

        //APPLYING BFS

        while(q.size() > 0){
            int node = q.front();

            q.pop();
            toposort.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(toposort.begin(), toposort.end());

        return toposort;
    }
};