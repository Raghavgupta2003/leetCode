class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //we will try to apply toposort here
        //but toposort deals with indegree

        //SAFE NODES: Nodes which have outdegree = 0

        //so can we reverse all the edges then play with indegree,
        //yes we can do;
        int n = graph.size();
        vector<int> indegree(n, 0);

        //reversing nodes
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safe;
        while(q.size() > 0){
            int node = q.front();

            q.pop();
            safe.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};