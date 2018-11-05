class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        unordered_map<char,int> hash;
        for(int i=0; i<s.size(); i++) {
            hash[s[i]] += 1;
        }
        int odd_num = 0;
        for(auto it = hash.begin(); it != hash.end(); it++)
        {
            if(it->second % 2 == 1) odd_num++;
        }
        return (odd_num<=1);
    }
};
