class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> brd=board;

        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 0;
                if(i>=1  && brd[i-1][j]){
                    count++;
                }
                if(i<m-1  && brd[i+1][j]){
                    count++;
                }
                if(j>=1 && brd[i][j-1]){
                    count++;
                }
                if(j<n-1 && brd[i][j+1]){
                    count++;
                }
                if(i>=1 && j>=1 && brd[i-1][j-1]){
                    count++;
                }
                if(i<m-1 && j>=1 && brd[i+1][j-1]){
                    count++;
                }
                if(i>=1 && j<n-1 && brd[i-1][j+1]){
                    count++;
                }
                if(i<m-1 && j<n-1 && brd[i+1][j+1]){
                    count++;
                }

                if(brd[i][j]){
                    if(count!=2 && count!=3) board[i][j] = 0;
                }else{
                    if(count==3) board[i][j]=1;
                }
            }
        }
    }
};