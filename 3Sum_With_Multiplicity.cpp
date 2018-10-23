class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        /*
            i + j + k == target, if i==j==k, C(i)/3
                                    i!=j==k, C(i) * C(j)/2
                                    i==j!=k, C(i)/2 * C(k)
                                    i!=j!=k, C(i) * C(j) * C(k)
        */
        unordered_map<int,long long> hash;
        long long NUM = (1e9+7);
        long long ans = 0;
        
        /* record each item's occurence */
        for(auto a : A) {
            if(hash.count(a) == 0) hash[a] = 1;
            else hash[a]++;
        }
        for( int i = 0; i <= target; i++ ) 
        {
            for( int j = i; j <= target; j++ ) 
            {
                int k = target-i-j;
                if( k < j ) continue;
                if( hash.count(i)==0 || hash.count(j)==0 || hash.count(k)==0 ) continue;
                if( i == j && j == k ) ans += (hash[i]*(hash[i]-1)*(hash[i]-2)/6);
                else if( i != j && j == k ) ans += (hash[i]*hash[j]*(hash[j]-1)/2);
                else if( i == j && j != k ) ans += (hash[i]*(hash[i]-1)/2*hash[k]);
                else ans += (hash[i]*hash[j]*hash[k]);
            }
        }
        //cout << ans << endl;
        return ans%NUM;
    }
};
