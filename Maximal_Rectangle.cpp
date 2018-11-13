class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        int max_area = 0;
        vector<int> prev_height(n+1,0);
        vector<int> curr_height(n+1,0);
        for( int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n; j++ ) 
                curr_height[j] = (matrix[i][j]) ? (prev_height[j]+(int)(matrix[i][j])) : 0;
            /* run stack algorithm */
            stack<pair<int,int>> stack;
            for( int j = 0; j <= n; j++ ) 
            {
                if( stack.empty() || stack.top().second<=curr_height[j] ) {
                    stack.push(make_pair(j,curr_height[j]));
                    continue;
                }
                while( !stack.empty() && stack.top().second>curr_height[j] )
                {   
                    auto info = stack.top();
                    stack.pop();
                    int width = stack.empty() ? j : j-1-stack.top().first;
                    int height = info.second;
                    max_area = max(max_area, width*height);
                }
                stack.push(make_pair(j,curr_height[j]));
            }
            prev_height = curr_height;
        }
        return max_area;
    }
};
