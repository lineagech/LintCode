class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if( arr.size() == 0 ) return 0;
        int left_max = arr[0];
        int left_min = arr[0];
        stack<pair<int,int>> record;
        
        record.push(make_pair(left_min,left_max));
        for(int i=1; i<arr.size(); i++)
        {
            if( record.size()>0 && arr[i]<record.top().second )
            {
                int next_left_min = min(arr[i],record.top().first);
                int next_left_max = record.top().second;
                while( record.size()>0 && 
                        next_left_min < record.top().second )
                {
                    record.pop();
                }
                record.push(make_pair(next_left_min,next_left_max));
            }
            else
            {
                record.push(make_pair(arr[i],arr[i]));
            }
        }
        return record.size();
    }
};
