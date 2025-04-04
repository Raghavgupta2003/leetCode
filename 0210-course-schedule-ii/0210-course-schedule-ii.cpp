class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // this question  is somewhat similar to toposort
        // or cycle detection by toposort
        // we are given eith reverse edges
        // we will correct the order of edges

        for(auto it : prerequisites){
            reverse(it.begin(), it.end());
        }

        // creating adj list
        int n = numCourses; //number of nodes
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
        }

        //Working with toposort

        //indegree
        vector<int> indegree(n);
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        //initialize queue
        //insert nodes whose indegree is 0

        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        //Applying BFS
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

        //returning 
        reverse(toposort.begin(), toposort.end());
        if(toposort.size() == n) return toposort; //NO cycle dependencies found
                                              // we are able to complete course

        return {}; // cyclic dependencies found;
    }
};