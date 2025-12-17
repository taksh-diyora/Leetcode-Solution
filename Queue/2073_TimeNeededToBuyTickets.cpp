class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tkt = 0;
        int idx = 0;
        int n = tickets.size();

        while(tickets[k]!=0){
            if(tickets[idx%n] == 0){
                idx++;
                continue;
            }

            tickets[idx%n]--;
            idx++;
            tkt++;
        }

        return tkt;
    }
};