class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        unordered_map<char,int> hash;
        if(k == 0 || s.size() == 0 ) return 0;
        int count = 0;
        int start = 0, end = 0;
        int ans = 0;
        while( end < s.size() )
        {
            if( hash.find(s[end]) == hash.end() )   
            {
                hash[s[end++]] = 1;
                count++;
            }
            else
            {
                if(hash[s[end]] == 0) count++;
                hash[s[end++]]++;
            }
            while( count > k )
            {
                hash[s[start]]--;
                if( hash[s[start]] == 0 ) count--;
                start++;
            }
            ans = max(ans, end-start);   
        }
        return ans;
    }
};
