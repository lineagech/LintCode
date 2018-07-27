class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    double minmaxGasDist(vector<int> &stations, int k) {
        // Write your code here
        if( stations.size() == 0 ) return 0.0;
        vector<double> stations_diff;
        sort(stations.begin(), stations.end());
        for( int i = 1; i < stations.size(); i++ )
            stations_diff.push_back( (double)(stations[i]-stations[i-1]) );   
        sort( stations_diff.begin(), stations_diff.end(), greater<double>() );
        
        double h = stations_diff[0]; 
        double l = 0.0;
        
        while( fabs(h-l) > 1e-6 )
        {
            double mid = (h+l)/2;
            int count = 0;
            for( auto diff : stations_diff )
            {
                if( can_divide((double)diff, mid) )
                    count += (int)((diff)/mid)-1;
                else
                    count += (int)((diff)/mid);
            }//cout<<mid<<","<<count<<endl;
            if( count <= k ) // too large
                h = mid;
            else
                l = mid;
        }
        return l; 
    }
    bool can_divide( double a, double b )
    {
        return ( (a/b-(int)(a/b)) < 1e-9 );
    }
};
