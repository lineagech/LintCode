class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if(nums.size() == 0)
            return result;
        int ex_re = std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        ex_re &= -ex_re;
        int tmp1 = 0;
        int tmp2 = 0;
        for(auto num : nums)
        {
            if((ex_re & num) == 0)
                tmp1 ^= num;
            else
                tmp2 ^= num;
        }
        result.push_back(tmp1);
        result.push_back(tmp2);
        return result;
    }
};
