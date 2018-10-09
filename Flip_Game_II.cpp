class Solution {
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    unordered_map<string,bool> hash;
    bool canWin(string &s) {
        // write your code here
        if(hash.find(s) != hash.end()) 
            return hash[s];
        if(s.size() == 0) return false;
        bool mustWin = false;
        for(int i = 0; i < s.size()-1; i++)
        {   
            if( s[i]=='+' && s[i+1]=='+' )
            {   
                s.replace(i, 1, "-");
                s.replace(i+1, 1, "-");
                mustWin |= !canWin(s);
                s.replace(i, 1, "+");
                s.replace(i+1, 1, "+");
            }
        }
        hash[s] = mustWin;
        return mustWin;
    }
};
