class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0;
        int n = price.size();
        int sp_size = special.size();
        for( int i=0; i<n; i++ ) ans += (price[i]*needs[i]);
        
        for( int i=0; i<sp_size; i++ )
        {
            bool valid = true;
            int discount = special[i][n];
            for( int j=0; j<n; j++ ) {
                valid = valid && (special[i][j] <= needs[j]);
                needs[j] -= special[i][j];
            }
            if( valid ) {
                ans = min(ans, discount+shoppingOffers(price, special, needs));
            }
            for( int j=0; j<n; j++ ) needs[j] += special[i][j];
        }
        return ans;
    }
};
