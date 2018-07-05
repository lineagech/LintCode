class Solution {
public:
    /**
     * @param nums: an array
     * @param n: an integer
     * @return: the minimum number of patches required
     */
    int minPatches(vector<int> &nums, int n) {
        // Write your code here
        long accu = 1, i = 0, ans = 0;
        while( accu <= n )
        {
            if( i<nums.size() && nums[i]<=accu )
            {
                accu += nums[i++];
            }
            else
            {
                accu += accu;
                ans++;
            }
        }
        return ans;
    }
};
