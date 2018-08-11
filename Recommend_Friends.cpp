class Solution {
public:
    /**
     * @param friends: people's friends
     * @param user: the user's id
     * @return: the person who most likely to know
     */
    class pair_hash
    {
    public:
        size_t operator()(pair<int,int> key) const
        {
            auto h1 = hash<int>{}(key.first);
            auto h2 = hash<int>{}(key.second);
            return h1^h2;
        }
    };
    int recommendFriends(vector<vector<int>> &friends, int user) {
        // Write your code here 
        map<int, int>Hashmap;
        for(int j = 0; j < friends[user].size(); j++) {
            Hashmap[friends[user][j]] = 1;
        }
        int cnt = 0, ans = -1;
        for(int i = 0; i < friends.size(); i++) {
            if(Hashmap[i] == 0 && i != user) {
                int temp = 0;
                for(int j = 0; j < friends[i].size(); j++) {
                    if(Hashmap[friends[i][j]] == 1) {
                        temp++;
                    }
                }
                if(temp > cnt) {
                    cnt = temp;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
