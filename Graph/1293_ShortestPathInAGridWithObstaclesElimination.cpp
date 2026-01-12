class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, k});
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k+1, 0)));
        vis[0][0][k] = 1;
        int minPath = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int remK = q.front().second;
                int row = q.front().first.first;
                int col = q.front().first.second;

                q.pop();
                if(row == m-1 && col == n-1){
                    return minPath;
                }

                for(int i=0; i<4; i++){
                    int r = row + dr[i];
                    int c = col + dc[i];

                    if(r>=0 && r<m && c>=0 && c<n){
                        int nextk = remK - grid[r][c];

                        if(nextk>=0 && !vis[r][c][nextk]){
                            vis[r][c][nextk] = 1;
                            q.push({{r, c}, nextk});
                        }
                    }
                }                
            }
            minPath++;
        }

        return -1;
    }
};