class Solution {
public:
    /**
     * @param point: a list of two-tuples
     * @return: a boolean, denote whether the polygon is convex
     */
    bool isConvex(vector<vector<int>> &point) {
        // write your code here
        if(point.size() <= 2) return false;
        int n = point.size();
        int dx1, dy1, dx2, dy2;
        int pre = 0;
        int outer_product;
        for(int i=1; i<point.size()+1; i++)
        {
            dx1 = point[(i-1)%n][0]-point[i%n][0];
            dy1 = point[(i-1)%n][1]-point[i%n][1];
            dx2 = point[(i+1)%n][0]-point[i%n][0];
            dy2 = point[(i+1)%n][1]-point[i%n][1];
            outer_product = (dx1*dy2)-(dx2*dy1);
            if(outer_product != 0) 
            {
                if(outer_product*pre < 0) return false;
                else pre = outer_product;
            }
        }
        return true;
    }
};
