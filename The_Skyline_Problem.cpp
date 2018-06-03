class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        // write your code here
        if(buildings.size() == 0) return vector<vector<int>>();
        typedef pair<int,int> event;
        vector<event> Events;
        auto myComp = [](pair<int,int> a, pair<int,int> b){
            if(a.first == b.first) return (a.second > b.second);
            return (a.first < b.first);
        };
        //multiset<pair<int,int>, decltype(myComp)> record(myComp);
        multiset<int> record;
        for(auto b : buildings)
        {
            Events.push_back({b[0],b[2]});
            Events.push_back({b[1],-1*b[2]});
        }
        sort(Events.begin(), Events.end(), [](event& a, event& b){
            if(a.first == b.first) return (a.second > b.second);
            return (a.first < b.first);
        });
        vector< vector<int> > tmp, ans;
        int prev_point = INT_MAX;
        for( auto it=Events.begin(); it!=Events.end(); it++)
        {
            bool entering = ((*it).second >= 0);
            int point = (*it).first;
            int height = (entering) ? ((*it).second) : (-1*((*it).second));
            if(entering) // entering point
            {
                if( record.size()== 0 || height > *(record.rbegin()) ) 
                {   
                    tmp.push_back({point,height});
                    //cout << point << "," << height << endl;
                }
                record.insert(height);
            }
            else
            {   
                //cout << point << "," << height <<","<<record.size() << endl;
                record.erase(record.equal_range(height).first);
                if( record.size()== 0 ||  height > *(record.rbegin()) )
                {
                    if(record.size()> 0 && height > *(record.rbegin()))
                        tmp.push_back({point,*(record.rbegin())});
                    if(record.size() == 0) 
                    {
                        tmp.push_back({point,0});
                        tmp.push_back({-1});
                    }        
                }
            }
            
        }
        for(int i=0; i<tmp.size()-1; i++)
        {
            if( tmp[i+1].size()!=1 && tmp[i].size()!=1)
                ans.push_back({tmp[i][0],tmp[i+1][0],tmp[i][1]});
        }

        return ans;
    }
    
    
};
