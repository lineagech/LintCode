class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0;
        stack<pair<int,int>> stack;
        stack.push(make_pair(-1, -1)); //dummy height
        for( int i = 0; i < height.size(); i++ )
        {
            while( height[i] < stack.top().second )
            {
                auto height_info = stack.top();
                stack.pop();
                max_area = max( (i-stack.top().first-1)*height_info.second, max_area );
            }
            if( height[i] == 0 ) {
                while( !stack.empty() ) stack.pop();
                stack.push(make_pair(i, -1)); 
            }   
            else {
                stack.push(make_pair(i, height[i]));
            }
        }
        while( stack.size() > 1 )
        {
            auto height_info = stack.top();
            stack.pop();
            max_area = max( ((int)height.size()-stack.top().first-1)*height_info.second, max_area );
        }
        return max_area;
    }
};
