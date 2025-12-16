class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for(int a: apple){
            apples+=a;
        }
        sort(capacity.begin(), capacity.end());
        int count = 0;
        for(int i = capacity.size()-1; i>=0; i--){
            count++;
            apples-=capacity[i];
            if(apples<=0) break;
        }

        return count;
    }
};