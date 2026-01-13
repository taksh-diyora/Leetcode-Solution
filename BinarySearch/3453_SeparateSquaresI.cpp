class Solution {
public:
    bool isLowerHalfLarger(vector<vector<int>>& squares, double midY){
        double low = 0, high = 0;

        for(auto& square: squares){
            double bottomY = square[1], side = square[2], topY = bottomY + side;
            if(topY <= midY){
                low += side*side;
            }else if(bottomY >= midY){
                high += side*side;
            }else{
                double below = midY - bottomY, above = topY - midY;

                low += below*side;
                high += above*side;
            }
        }

        return low>=high;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double minY = INT_MAX;
        double maxY = INT_MIN;
        for(auto& v: squares){
            minY = min(minY, v[1]*1.0);
            maxY = max(maxY, v[1]+v[2]*1.0);
        }

        double precis = 1e-5;

        while(maxY - minY > precis){
            double midY = (minY+maxY)/2;
            if(isLowerHalfLarger(squares, midY)){
                maxY = midY;
            }else{
                minY = midY;
            }
        }

        return minY;
    }
};