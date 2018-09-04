class Solution {
public:
    /**
     * @param ghosts: a 2D integer array
     * @param target: a integer array
     * @return: return boolean
     */
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        // write your code here
        if( target.size() != 2 ) return false;
        //if( target[0] < 0 || target[1] < 0 ) return false;
        int target_distance = distance( 0, 0, target[0], target[1] );
        
        for( auto g : ghosts )
        {
            if( distance(target[0], target[1], g[0], g[1]) <= target_distance ) return false;
        }
        
        return true;
    }
    int distance( int sx, int sy, int dx, int dy )
    {
        return abs(sx-dx)+abs(sy-dy);
    }
};
