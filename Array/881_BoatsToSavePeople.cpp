class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int count = 0;

        while(right>=left){
            int total = people[right]+people[left];

            if(total<=limit){
                right--;
                left++;
            }else{
                right--;
            }
            count++;
        }

        return count;
    }
};