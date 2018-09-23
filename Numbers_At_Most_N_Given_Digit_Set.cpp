class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N, bool init=true) {
        string str_N = to_string(N);
        int str_N_len = str_N.size();
        int D_size = D.size();
        int ans = 0;
        
        // check each number of digit
        for( int i = 1; i < str_N_len && init; i++ ) {
            ans += pow(D_size,i);
        }
        for( int i = 0; i < D_size; i++ ) 
        {
            if( D[i][0] < str_N[0] )
                ans += pow(D_size,str_N_len-1);
            else if( D[i][0] == str_N[0] ){
                string next_N = str_N.substr(1);
                if( next_N.empty() ) {
                    ans++;
                    continue;
                }
                if( next_N[0] == '0' ) {
                    continue;
                }
                ans += atMostNGivenDigitSet(D, stoi(next_N), false);
            }
        }
        return ans;
    }
};
