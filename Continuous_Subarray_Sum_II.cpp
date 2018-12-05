class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        int n = A.size();
        if( n == 0) return {};
        long long con_max_val = INT_MIN, max_val = INT_MIN;
        int curr_start, curr_end, start, end;
        int total = 0;
        for( int i = 0; i < A.size(); i++ )
        {
            total += A[i];
            if( con_max_val + A[i] < A[i] ) {
                con_max_val = A[i];
                curr_start = i;
            }
            else {
                con_max_val += A[i];
            }
            curr_end = i;
            if( con_max_val > max_val ) {
                max_val = con_max_val;
                start = curr_start;
                end = curr_end;
            }
        }
        /* find min value */
        long long con_min_val = INT_MAX, min_val = INT_MAX;
        for( int i = 0; i < A.size()-1; i++ )
        {
            if( con_min_val + A[i] > A[i] ) {
                con_min_val = A[i];
                curr_start = i;
            } 
            else{
                con_min_val += A[i];
            }
            curr_end = i;
            if( con_min_val < min_val && total-con_min_val > max_val )
            {
                min_val = con_min_val;
                max_val = total-con_min_val;
                start = (curr_end+1) % n;
                end = (curr_start-1+n) % n;
            }
        }

        return {start, end};
    }
};
