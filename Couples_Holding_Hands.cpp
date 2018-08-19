class Solution {
public:
    /**
     * @param row: the couples' initial seating
     * @return: the minimum number of swaps
     */
    int minSwapsCouples(vector<int> &row) {
        // Write your code here
        int n = row.size();
        if( n % 2 != 0 ) return 0;
        int ans = 0;
        vector<int> pos(n);
        for( int i=0; i<n; i++ ) pos[row[i]] = i; // for swap
        
        for( int i=0; i<n; i+=2 )
        {
            int couple_1 = row[i];
            int couple_2 = (couple_1 ^ 0x1); 
            if( couple_2 != row[i+1] ) //swap
            {   
                int tmp_row_value = row[i+1];
                swap_vec(row, i+1, pos[couple_2]);//swap(row[i+1], row[pos[couple_2]]);
                swap_vec(pos, tmp_row_value, couple_2);//swap(pos[row[i+1]], pos[couple_2]);
                ans++;
            }
        }
        return ans;
    }
    void swap_vec(vector<int>& arr, int pos1, int pos2)
    {
        int tmp = arr[pos2];
        arr[pos2] = arr[pos1];
        arr[pos1] = tmp;
    }
};
