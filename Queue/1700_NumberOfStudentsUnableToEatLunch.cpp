class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int ones = 0;
        for(int i: students){
            if(i) ones++;
        }
        int zrs = n-ones;

        for(int i=0; i<n; i++){
            if(sandwiches[i]){
                if(!ones) return n-i;
                ones--;
            }else{
                if(!zrs) return n-i;
                zrs--;
            }
        } 

        return 0;
    }
};