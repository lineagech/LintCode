class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        int n = nums.size();
        vector<int> preSum(n+1,0);
        unordered_map<int,int> hash;
        for( int i=0; i<nums.size(); i++ ) {
            preSum[i+1]=preSum[i]+nums[i];
            if( preSum[i+1] == 0 ) return {0, i};
            if( hash.count(preSum[i+1]) ) {
                return {hash[preSum[i+1]], i};
            }
            hash[preSum[i+1]] = i+1;
        }
        return {};
    }
};
