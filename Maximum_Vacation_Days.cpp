class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        // Write your code here
        //
        if( flights.size() == 0 || days.size() == 0 ) return 0;
        vector<vector<int>> dp( flights.size(), vector<int>(days[0].size(), 0) );
        int maxdays = 0;
        for (int city=0; city<flights.size(); city++) {
            dp[city][days[0].size()-1] = days[city][days[0].size()-1];
        }
        for( int week=days[0].size()-2; week>=0; week-- )
        {
            for( int city=0; city<flights.size(); city++ )
            {
                dp[city][week] = get_week_max_days(flights, days, dp, city, week+1) + days[city][week];
            }
        }
        return get_week_max_days(flights, days, dp, 0, 0);
    }
    int get_week_max_days( vector<vector<int>> &flights, vector<vector<int>> &days, vector<vector<int>>& dp, int city, int week )
    {
        int _max = dp[city][week]; //stay in the same city
        for( int i=0; i<flights.size(); i++ )
        {   
            if( flights[city][i] == 1 )
                _max = max( _max, dp[i][week] );
        }
        return _max;
    }
    
};
