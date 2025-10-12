class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        for(int i=0;i<m;i++) {
            int empty=n-1;
            for(int j=n-1;j>=0;j--) {
                if(boxGrid[i][j]=='*') empty=j-1;
                else if(boxGrid[i][j]=='#') swap(boxGrid[i][j],boxGrid[i][empty--]);
            }
        }
        vector<vector<char>> box(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                box[j][m-1-i]=boxGrid[i][j];
            }
        }
        return box;
    }
};