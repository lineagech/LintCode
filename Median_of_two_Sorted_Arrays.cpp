class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        if(A.size() < B.size()) swap(A, B);
        int m = A.size(); // longer
        int n = B.size(); // shorter
        
        bool is_odd = ((m+n)%2==1);
        int half_len = (m+n)/2;
        
        int A_start = 0; 
        int A_end = m;
        int m1, m2;
        while(true)
        {
            int A_mid = (A_start+A_end)/2; // A_mid's element
            int B_mid = half_len-A_mid;
            
            /* B[B_mid-1] < A[A_mid] && A[A_mid-1] < B[B_mid] */
            if( (B_mid > 0 && A_mid < m && B[B_mid-1] > A[A_mid]) )
            {
                A_start = A_mid+1;
            }
            else if( (B_mid < 0) || 
                     (A_mid > 0 && B_mid < n && A[A_mid-1] > B[B_mid])  )
            {
                A_end = A_mid-1;
            }
            else
            {
                if(B_mid == 0) // no element from B
                {
                    m1 = A[A_mid-1];
                    if(m==n) m2 = B[B_mid];
                    else m2 = A[A_mid];
                }
                else if( A_mid == 0 ) // no element from A
                {
                    m1 = B[B_mid-1];
                    m2 = A[A_mid];
                }
                else
                {
                    m1 = max(A[A_mid-1], B[B_mid-1]);
                    m2 = min(A[A_mid], B[B_mid]);
                }
                if(is_odd) return m2;
                else return (m1+m2)/2.0;
            }
            
        }

    }
};
