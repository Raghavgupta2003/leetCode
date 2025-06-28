class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        //{u, v}
        //since we have to complete course v before u
        //adj[v].push_back(u);

        int n = numCourses; //number of nodes

        vector<int> indegree(n, 0);

        vector<vector<int>> adj(n, vector<int>(0));
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        //khans Algorithm

        queue<int> q;
        for(int i=0; i<indegree.size(); i++){\
            // cout<<indegree[i]<<" ";
            if(indegree[i] == 0) q.push(i); //pushing node whose indegree is zero
        }
        
        vector<int> toposort;
    
        while(q.size() > 0){
            int node = q.front();
            q.pop();

            toposort.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(toposort.size() == n) return toposort;

        return {};
    }
};