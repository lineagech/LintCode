class Solution {
public:
    /**
     * @param A: an array
     * @param B: an array
     * @return: the minimum number of swaps to make both sequences strictly increasing
     */
    int minSwap(vector<int> &A, vector<int> &B) {
        // Write your code here
        int n = A.size();
        vector<int> keep(n, INT_MAX);
        vector<int> swap(n, INT_MAX);
        keep[0] = 0;
        swap[0] = 1;
        for(int i=1; i<n; i++)
        {
            if(A[i]>A[i-1] && B[i]>B[i-1])
            {
                keep[i] = keep[i-1]; // no swap
                swap[i] = swap[i-1]+1;// both swap
            }
            if(A[i]>B[i-1] && B[i]>A[i-1])
            {
                keep[i] = min(keep[i],swap[i-1]);//i-1 swap
                swap[i] = min(swap[i],keep[i-1]+1);//i swap
            }
        }
        return min(keep[n-1], swap[n-1]);
    }
};
