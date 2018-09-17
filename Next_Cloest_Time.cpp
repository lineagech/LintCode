class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here
        vector<int> time_nu;
        string ans = time;
        if( time.size() != 5 ) return "";
        for( auto s : time ) 
            if( s >= '0' && s <= '9' ) 
                time_nu.push_back(s-'0');
            
        sort(time_nu.begin(), time_nu.end());
        
        bool carrying = false;
        for( int i=ans.size()-1; i>=0; i-- )
        {
            if( ans[i] == ':' ) continue;
            int value = ans[i]-'0';
            // look for next greter number, if there is carrying, should iterate next
            for( int j=0; j<time_nu.size(); j++ )
            {
                if( time_nu[j] > value  )
                {   
                    ans.replace(i, 1, to_string(time_nu[j]));
                    if( isValid(ans) )
                    {
                        return ans;
                    }
                    ans.replace(i, 1, to_string(value));
                }
            }
            // replace the smallest number and continue
            ans.replace(i, 1, to_string(time_nu[0]));
        }
        return ans;
    }
    bool isValid(string& time_str)
    {
        int hour = (time_str[0]-'0')*10 + (time_str[1]-'0');
        int miniute = (time_str[3]-'0')*10 + (time_str[4]-'0');
        
        return (hour <= 24) && (miniute <= 59);
    }

};
