// class Solution {
// public:
//     bool dfs(int node, vector<int>& visited, int color, vector<vector<int>>& graph){
//         visited[node] = color;

//         for(auto it : graph[node]){
//             if(visited[it] == -1){ //not visited
//                 if(!dfs(it, visited, !color, graph)) return false;
//             }
//             else{
//                 // already visited
//                 // check if it has same color..?
//                 // if same color NOT a bipartite which means return false;
//                 if(visited[it] == color){
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size(); //number of nodes

//         //in visited array we store color as 0 and 1 
//         vector<int> visited(n, -1);
//         int color = 0;
//         for(int i=0; i<n; i++){
//             if(visited[i] == -1){ //not visited 
//                 if(!dfs(i, visited, color, graph)) return false;
//             }
//         }

//         return true;
//     }
// };

//-----------------------------BFS--------------------------------------
class Solution {
public:
    bool BFS(int node, vector<int>& visited, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        visited[node] = 0; //0th is colored with 0;

        while(q.size() > 0){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(visited[it] == -1){
                    q.push(it); 
                    visited[it] = !visited[node];//coloring with opposite color of node
                }else{
                    //already colored, visited
                    if(visited[it] == visited[node]) return false;
                }
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); //number of nodes

        //in visited array we store color as 0 and 1 
        vector<int> visited(n, -1);

        for(int i=0; i<n; i++){
            if(visited[i] == -1){
                if(!BFS(i, visited, graph)) return false;
            }
        }
        return true;
    }
};