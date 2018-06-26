class Solution {
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    class MyComp{
    public:
	    bool operator()(pair<int,pair<int,int>>& l, pair<int,pair<int,int>>& r)
	    {
		    return (l.first > r.first) || (l.first==r.first && l.second>r.second); 
	    }
    };
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, MyComp> pri_queue; // default is less comparison
        vector<int> hash( A.size()*B.size(), 0 );
        int A_size = A.size();
        int B_size = B.size();
        int count = 0;

        if((A_size == 0 && B_size == 0) || ( (A_size!=0 && B_size!=0) && (A_size*B_size)<k ) ) return -1;
        else if(A.size() == 0) {
    	    return B[k-1];
        }
        else if(B.size() == 0){ 
    	    return A[k-1];
        }
        else {
    	    hash[ 0*B_size + 0 ] = 1;
    	    pri_queue.push( make_pair(A[0]+B[0], make_pair(0,0)) );
        }


        while( !pri_queue.empty() )
        {
    	    // get currenly the smallest and infer other possible smallest ones
    	    pair<int,pair<int,int>> curr_smallest = pri_queue.top();
    	    int curr_value = curr_smallest.first;
    	    int A_idx = curr_smallest.second.first, B_idx = curr_smallest.second.second;
    	    int next_A_idx, next_B_idx;
    	    pri_queue.pop();
    	    count++; 
    	    if( count == k ) return curr_value;
    
    	    // possible next smallest is (A_idx+1,B_idx) or (A_idx, B_idx+1)
    	    next_A_idx = (A_idx+1);
    	    next_B_idx = B_idx;
    	    if( next_A_idx < A_size && hash[ next_A_idx*B_size + next_B_idx ] == 0) { 
    	    	pri_queue.push( make_pair(A[next_A_idx]+B[next_B_idx], 
    	    	                make_pair(next_A_idx,next_B_idx)) );
    	    	hash[ next_A_idx*B_size + next_B_idx ] = 1;
    	    }

    	    next_A_idx = A_idx;
    	    next_B_idx = (B_idx+1);
    	    if( next_B_idx < B_size && hash[ next_A_idx*B_size + next_B_idx ] == 0) {
    	    	pri_queue.push( make_pair(A[next_A_idx]+B[next_B_idx], 
    	    	                make_pair(next_A_idx,next_B_idx)) );
    	    	hash[ next_A_idx*B_size + next_B_idx ] = 1;
    	    }
        }
        return -1;
    }
};
