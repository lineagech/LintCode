class Solution {
public:
    class MyComp {
    int findMinDifference(vector<string>& timePoints) {
        //sort(timePoints.begin(), timePoints.end(), MyComp());
        if( timePoints.size() == 0 ) return 0;
        vector<int> time(timePoints.size());
        for( int i=0; i<timePoints.size(); i++ )
        {
            int split = timePoints[i].find(":");
            timePoints[i].replace(split, 1, " ");
            stringstream ss(timePoints[i]); 
            int hour, miniute; 
            ss >> hour; 
            ss >> miniute;
            time[i] = hour*60+miniute; 
        }
        sort(time.begin(), time.end());
        int min_diff = INT_MAX;
        for( int i=1; i<time.size(); i++ )
        {
            min_diff = min( min_diff, time[i]-time[i-1] );
        }
        int final_diff = (time.front()-time.back() < 0) ? (time.front()-time.back()+1440) : (time.front()-time.back());
        min_diff = min( min_diff, final_diff );
        return min_diff;
    }
};
