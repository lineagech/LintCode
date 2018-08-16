class Solution {
public:
    /**
     * @param matrix: List[List[int]]
     * @param k: a integer
     * @return: return a integer
     */
    typedef pair<int,int> point;
    class MyComp
    {
    public:
        bool operator()(point a, point b) // greater 
        {
            return (a.second > b.second);
        }
    };
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        priority_queue<point, vector<point>, MyComp> min_heap;
        int n = matrix.size();
        if( n == 0 ) return 0;
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int ans;
        
        min_heap.push(make_pair(0,matrix[0][0]));
        visited[0][0] = true;
        for( int i = 0; i < k; i++ )
        {
            point curr = min_heap.top();
            min_heap.pop();
            int next_i = curr.first/m+1;
            int next_j = curr.first%m;
            if( check_range(next_i, next_j, n, m) && !visited[next_i][next_j])
            {
                min_heap.push(make_pair(next_i*m+next_j, matrix[next_i][next_j]));
                visited[next_i][next_j] = true;
            }
            
            next_i = curr.first/m;
            next_j = curr.first%m+1;
            if( check_range(next_i, next_j, n, m) && !visited[next_i][next_j])
            {
                min_heap.push(make_pair(next_i*m+next_j, matrix[next_i][next_j]));
                visited[next_i][next_j] = true;
            }
                
            ans = curr.second;
        }
        return ans;
    }
    bool check_range(int i, int j, int n, int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
};
