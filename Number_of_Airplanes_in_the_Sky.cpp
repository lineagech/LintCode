/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        multiset<pair<int,int>> tree;
        int count = 0;
        int ans = 0;
        for( auto airplane : airplanes ) {
            tree.insert(make_pair(airplane.start,1));
            tree.insert(make_pair(airplane.end,-1));
        }
        for( auto p : tree ) {
            count += (p.second);
            ans = max(ans, count);
        }
        return ans;
    }
};
