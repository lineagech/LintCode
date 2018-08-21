class Solution {
public:
    /**
     * @param people: a random list of people
     * @return: the queue that be reconstructed
     */
    typedef pair<int,int> node;
    
    template<class T>
    class MyComp
    {
    public:
        bool operator()(T a, T b)
        {
            return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]); 
        }
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // write your code here
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), MyComp<vector<int>>());
        for( int i=0; i<people.size(); i++ )
        {
            int acc = 0;
            int idx;
            for( idx=0; idx<ans.size(); idx++ )
            {
                if( people[i][0] <= ans[idx][0] ) acc++;
                if( acc > people[i][1] ) break;
            }
            ans.insert(ans.begin()+idx, people[i]);
            //cout << acc <<":"<<people[i][0]<<","<<people[i][1]<<endl;
        }
        
        return ans;
    }
};
