class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int m = board.size();
        if( m == 0 ) return -1;
        int n = board[0].size();
        unordered_set<string> hash;
        int ans = 0;
        
        int zero_num = 0, one_num = 0;
        string firstPattern, secPattern;
        string golden_firstPattern_col, golden_secPattern_col;
        string golden_firstPattern_row, golden_secPattern_row;
        // check 0, 1 number
        for(int i=0; i<n; i++)
        {
            if(board[0][i] == 1)
            {
                one_num++;
                firstPattern += "1";
                secPattern += "0";
            }
            else
            {
                zero_num++;
                firstPattern += "0";
                secPattern += "1";
            }
        }
        if( n%2==0 && one_num!=zero_num ) return -1;
        if( n%2==1 && abs(one_num-zero_num)!=1 ) return -1;
        hash.insert(firstPattern);
        hash.insert(secPattern);
        
        // check row pattern num 
        int firstPattern_num = 1, secPattern_num = 0;
        string row_Pattern = "1";
        for(int i=1; i<m; i++)
        {
            string curr;
            for(int j=0; j<n; j++)
                curr += (board[i][j]==1) ? "1" : "0";
            if(curr == firstPattern) {
                firstPattern_num++;
                row_Pattern += "1";
            }
            else if( curr == secPattern ) {
                secPattern_num++;
                row_Pattern += "0";
            }
            else return -1;
        }
        if( m%2==0 && firstPattern_num!=secPattern_num ) return -1;
        if( m%2==1 && abs(firstPattern_num-secPattern_num)!=1 ) return -1;
        
        // check interchange num
        golden_firstPattern_col 
            = GetGoldenPattern(n, (n%2==1) ? (one_num>zero_num ? 1 : 0) : (0) );
        golden_secPattern_col 
            = GetGoldenPattern(n, (n%2==1) ? (one_num>zero_num ? 0 : 1) : (1) );
            
        golden_firstPattern_row 
            = GetGoldenPattern(m, (m%2==1) ? (firstPattern_num>secPattern_num ? 1 : 0) : (0) );
        golden_secPattern_row 
            = GetGoldenPattern(m, (m%2==1) ? (firstPattern_num>secPattern_num ? 0 : 1) : (1) );
        
        if( n % 2 == 1)
            ans += find_distance(firstPattern, golden_firstPattern_col);
        else
            ans += min( find_distance(firstPattern, golden_firstPattern_col),
                    find_distance(firstPattern, golden_secPattern_col));
        if( m % 2 == 1 )
            ans += find_distance(row_Pattern, golden_firstPattern_row);
        else
            ans += min( find_distance(row_Pattern, golden_firstPattern_row),
                    find_distance(row_Pattern, golden_secPattern_row));
        
        return ans;
    }
    int find_distance(string a, string b)
    {
        int ans = 0;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != b[i]) ans++;
        }
        return ans/2;
    }
    
    string GetGoldenPattern(int size, int start_num)
    {
        string ans;
        for(int i=0; i<size; i++)
        {
            ans += to_string(start_num);
            start_num ^= 0x1;
        }
        return ans;
    }
};
