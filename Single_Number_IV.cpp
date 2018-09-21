class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        // Write your code here
        int result = 0;
        for(auto n : nums)
            result ^= n;
        return result;
    }
};
