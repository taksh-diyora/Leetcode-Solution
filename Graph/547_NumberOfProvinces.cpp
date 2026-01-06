class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        if(visited[i] == true) return;
        visited[i] = true;

        for(int x = 0; x < isConnected.size(); x++){
            if(isConnected[i][x]==1 && visited[x]==false){
                dfs(isConnected, visited, x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int comp = 0;

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(isConnected, visited, i);
                comp+=1;
            }
        }

        return comp;
    }
};