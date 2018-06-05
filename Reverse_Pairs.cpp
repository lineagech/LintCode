class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        vector<int> bin_indexed_tree(A.size()+1, 0);
        vector<int> sorted_A(A.begin(), A.end());
        sort(sorted_A.begin(), sorted_A.end()); // O(nlogn)
        long long ans = 0;
        for(int i=A.size()-1; i>=0; i--)
        {
            int bit_index = find_index(sorted_A, A[i]);
            ans += (long long)bit_query(bin_indexed_tree,bit_index);
            bit_update(bin_indexed_tree, bit_index+1);
        }
        return ans;
    }
    int find_index(vector<int>& A, int value)
    {
        int ans;
        ans = lower_bound(A.begin(),A.end(),value) - A.begin();
        return ans;
    }
    int bit_query(vector<int>& bin_indexed_tree, int bit_index)
    {
        int sum = 0;
        while( bit_index > 0 )
        {
            sum += bin_indexed_tree[bit_index];
            bit_index -= (bit_index & ~(bit_index-1));
        }
        return sum;
    }
    void bit_update(vector<int>& bin_indexed_tree, int bit_index)
    {
        while(bit_index < bin_indexed_tree.size())
        {
            bin_indexed_tree[bit_index] += 1;
            bit_index += (bit_index & ~(bit_index-1));
        }
    }
    
};
