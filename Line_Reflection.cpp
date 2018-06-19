class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        // Write your code here
        if(points.size() == 1) return false;
        int most_left = INT_MAX;
        int most_right = INT_MIN;
        unordered_map<int,unordered_set<int>> hash_point;
        for( auto p : points )
        {
            most_left = min(p[0], most_left);
            most_right = max(p[0], most_right);
            auto it = hash_point.find(p[1]);
            if(it == hash_point.end())
            {
                unordered_set<int> tmp;
                hash_point[p[1]] = tmp;
                hash_point[p[1]].insert(p[0]);
            }
            else
                (it->second).insert(p[0]);
        }
        double mid_line = (most_left+most_right)/2.0;
        for( auto p : points )
        {
            int reflect = (int)(2*mid_line-p[0]);
            auto it = hash_point[p[1]].find(reflect);
            if( it == hash_point[p[1]].end() ) return false;
        }
        return true;
    }
};
