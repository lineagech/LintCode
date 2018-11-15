class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        int m = A.size();
        if( m == 0 ) return vector<int>();
        int n = A[0].size();
        int curr_i = 0, curr_j = 0;
        while( true )
        {
            if( curr_i-1>=0 && A[curr_i-1][curr_j]<A[curr_i][curr_j] &&
                curr_j-1>=0 && A[curr_i][curr_j-1]<A[curr_i][curr_j] &&
                curr_i+1<m && A[curr_i+1][curr_j]<A[curr_i][curr_j] &&
                curr_j+1<n && A[curr_i][curr_j+1]<A[curr_i][curr_j] )
            {
                return {curr_i,curr_j};        
            }
            else if( curr_i+1<m && A[curr_i][curr_j]<A[curr_i+1][curr_j] )
            {
                curr_i++;
            }
            else if( curr_j+1<n && A[curr_i][curr_j]<A[curr_i][curr_j+1] )
            {
                curr_j++;
            }
        }
    }
};
