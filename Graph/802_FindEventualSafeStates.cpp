class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& processing, int i, vector<int>& map){
        if(map[i]!=-1) return map[i];
        if(graph[i].size()==0) return true;
        if(processing[i] == 1) return false;
        processing[i] = 1;

        for(int v: graph[i]){
            if(dfs(graph, processing, v, map) == false){
                map[i] = 0;
                return false;
            }
        }

        processing[i] = 0;
        map[i] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isProcessing(n, 0);
        vector<int> res;
        vector<int> map(n, -1);
        
        for(int i=0; i<n; i++){
            if(dfs(graph, isProcessing, i, map)){
                res.push_back(i);
            }
        }
        return res;
    }
};