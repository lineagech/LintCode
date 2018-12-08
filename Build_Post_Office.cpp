class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int m = grid.size();
        if( m == 0 ) return -1;
        int n = grid[0].size();
        vector<int> xPos, yPos;
        for( int i=0; i<m; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( grid[i][j] == 1 ) {
                    xPos.push_back(i);
                    yPos.push_back(j);
                }
            }
        }
        if( xPos.size()==0 ) return 0;
        sort(xPos.begin(), xPos.end());
        sort(yPos.begin(), yPos.end());
        vector<int> xPreSum(xPos.size(), 0);
        vector<int> yPreSum(yPos.size(), 0);
        xPreSum[0] = xPos[0]; 
        yPreSum[0] = yPos[0]; 
        for( int i=1; i<xPos.size(); i++ ) xPreSum[i]=xPreSum[i-1]+xPos[i];
        for( int i=1; i<yPos.size(); i++ ) yPreSum[i]=yPreSum[i-1]+yPos[i];
        
        int ans = INT_MAX;
        for( int i=0; i<m; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( grid[i][j] == 0 ) 
                {
                    int dist = 0;
                    int x_tmp = lower_bound(xPos.begin(), xPos.end(), i)-xPos.begin();
                    int y_tmp = lower_bound(yPos.begin(), yPos.end(), j)-yPos.begin();
                    int prev_preSum = (x_tmp>0) ? xPreSum[x_tmp-1] : 0;
                    dist += x_tmp*i-prev_preSum + xPreSum.back()-prev_preSum-(xPreSum.size()-x_tmp)*i;
                    prev_preSum = (y_tmp>0) ? yPreSum[y_tmp-1] : 0;
                    dist += y_tmp*j-prev_preSum + yPreSum.back()-prev_preSum-(yPreSum.size()-y_tmp)*j;
                    ans = min(ans, dist);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
