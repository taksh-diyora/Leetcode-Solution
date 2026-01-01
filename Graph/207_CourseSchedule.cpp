class Solution {
public:
    bool isCyclic(vector<int>& visited, vector<vector<int>>& adj, int curr){
        if(visited[curr]==2) return true;

        visited[curr] = 2;
        for(int i=0; i<adj[curr].size(); i++){
            if(visited[adj[curr][i]] != 1){
                if(isCyclic(visited, adj, adj[curr][i])){
                    return true;
                }
            }
        }

        visited[curr] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> vis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(vis[i]==0){
                if(isCyclic(vis, adj, i)){
                    return false;
                }
            }
        }

        return true;
    }
};