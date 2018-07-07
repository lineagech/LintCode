class Solution {
public:
    /**
     * @param x: The end points set of edges
     * @param y: The end points set of edges
     * @param d: The length of edges
     * @return: Return the index of the fermat point
     */
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d)
    {
        // Write your code here
        n = x.size()+1;
        vector<vector<pair<int,int>>> graph(n+1);
        vector<long long> dp(n+1);
        vector<int> np(n+1);
        for( int i=0; i<x.size(); i++ )
        {
            graph[x[i]].push_back(make_pair(y[i],d[i]));
            graph[y[i]].push_back(make_pair(x[i],d[i]));
        }
        dfs( graph, dp, np, 1, 0 );
        long long ans = dp[1];
        int index = 1;
        find_Fermet( graph, dp, np, 1, 0, dp[1], ans, index );
        return index;
    }
    void find_Fermet( vector<vector<pair<int,int>>>& graph, vector<long long>& dp, vector<int>& np, int source, int source_parent, long long sum, long long& ans, int& index )
    {
        for( int i=0; i<graph[source].size(); i++ )
        {
            int next_desti = graph[source][i].first;
            if( next_desti == source_parent ) continue;
            long long next_sum = (sum - (long long)np[next_desti]*(long long)graph[source][i].second)/* source's others root sum */
                               + ((long long)(n-np[next_desti])*(long long)graph[source][i].second); /**/
            if( next_sum < ans || ( next_sum == ans && next_desti < index ) )
            {
                ans = next_sum;
                index = next_desti;
            }
            find_Fermet( graph, dp, np, next_desti, source, next_sum, ans, index );
        }
    }
    
    void dfs( vector<vector<pair<int,int>>>& graph, vector<long long>& dp, vector<int>& np, int source, int source_parent )
    {   
        dp[source] = 0;
        np[source] = 1;
        for( int i=0; i<graph[source].size(); i++ )
        {
            int next_desti = graph[source][i].first;
            if( next_desti == source_parent ) continue;
            dfs( graph, dp, np, next_desti, source );
            dp[source] += (dp[next_desti] + (long long)np[next_desti]*(long long)graph[source][i].second);
            np[source] += np[next_desti];
        }
    }
    int n;
};
