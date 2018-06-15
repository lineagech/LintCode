class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // Write your code here 
        if(n==0) return 1;
        int ans = 0;
        int count = 9;
        for(int i=9; i>(9-n+1); i--)
            count *= i;
        ans += count;
        count = 9;
        if(n >= 1) ans += 1;
        if(n >= 2) ans += 9;
        if(n >= 3)
        {
            for(int i=0; i<n-2; i++)
            {
                count *= (9-i);
                ans += count;
            }
        }
        return ans;
    }
};
