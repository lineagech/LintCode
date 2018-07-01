class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    class MyComp 
    {
    public:
        bool operator()(pair<int,int>& a, pair<int,int>& b)
        {
            return ((a.first > b.first) || 
                   (a.first == b.first && a.second > b.second));
        }
    };
    int copyBooksII(int n, vector<int> &times) {
        // write your code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyComp> min_heap;
        if( times.size() == 0 ) return 0;
        for( auto t : times )
            min_heap.push( make_pair(t,t) );
        int ans = 0;
        for( int i=0; i<n; i++ )
        {
            int unit = min_heap.top().second; 
            ans = min_heap.top().first;
            min_heap.pop();
            min_heap.push( make_pair(ans+unit,unit) );
        }
        return ans;
    }
};
