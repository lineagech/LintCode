class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        // Write your code here
        if(color.size() != 7) return "";
        string ans = "#";
        for(int i=0; i<3; i++)
        {
            int distance = INT_MAX;
            char candidate;
            for(int offset=-1; offset<=1; offset++)
            {
                char tmp_cad = color[2*i+1]+offset;
                if( !((tmp_cad>='0' && tmp_cad<='9') || (tmp_cad>='a' && tmp_cad<='f')) ) 
                    continue;
                int tmp_dis = ((hex_map[color[2*i+1]]-hex_map[tmp_cad])*16 
                             + (hex_map[color[2*i+2]]-hex_map[tmp_cad]));
                tmp_dis *= tmp_dis;
                if(tmp_dis < distance)
                {
                    distance = tmp_dis;
                    candidate = tmp_cad;
                }
            }
            string str_cand(1, candidate);
            ans = ans+str_cand+str_cand;
        }
        cout << ans << endl;
        return ans;
    }
    unordered_map<char,int> hex_map = {
        {'0',0},
        {'1',1},
        {'2',2},
        {'3',3},
        {'4',4},
        {'5',5},
        {'6',6},
        {'7',7},
        {'8',8},
        {'9',9},
        {'a',10},
        {'b',11},
        {'c',12},
        {'d',13},
        {'e',14},
        {'f',15}
    };
    
};
