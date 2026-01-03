class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        int rNode = n;
        while(rNode > 2){
            int sz = q.size();
            rNode -= sz;

            for(int i=0; i<sz; i++){
                int node = q.front();
                q.pop();
                for(int neigh: adj[node]){
                    degree[neigh]--;
                    if(degree[neigh] == 1){
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};