class Solution {
public:
    /**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
     
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        // write your code here
        int LB = 0;
        int LT = 1;
        int RB = 2;
        int RT = 3;
        unordered_map< pair<int,int>, int, pair_hash > hash; //point, state
        pair<int,int> left_bottom;
        pair<int,int> left_top;
        pair<int,int> right_bottom;
        pair<int,int> right_top;
        int area_sum = 0;
        
        if( rectangles.size() == 0 ) return false;
        for( auto rec : rectangles )
        {
            left_bottom     = { rec[0], rec[1] };
            left_top        = { rec[0], rec[3] };
            right_bottom    = { rec[2], rec[1] };
            right_top       = { rec[2], rec[3] };
            
            if( (hash[left_bottom] & (1<<LB)) != 0 ) return false;
            hash[left_bottom] |= 1<<LB;
            
            if( (hash[left_top] & (1<<LT)) != 0 ) return false;
            hash[left_top] |= 1<<LT;
            
            if( (hash[right_bottom] & (1<<RB)) != 0 ) return false;
            hash[right_bottom] |= 1<<RB;
            
            if( (hash[right_top] & (1<<RT)) != 0 ) return false;
            hash[right_top] |= 1<<RT;
            
            area_sum += (rec[2]-rec[0])*(rec[3]-rec[1]);
        }
        int count[4] = {0, 0, 0, 0};
        for( auto it = hash.begin(); it != hash.end(); it++ )
        {
            if( it->second == (1<<LB) ) {
                if( count[LB] > 0 ) return false;
                left_bottom.first = it->first.first;
                left_bottom.second = it->first.second;
                count[LB]++;
            }
            if( it->second == (1<<RB) ) {
                if( count[RB] > 0 ) return false;
                right_bottom.first = it->first.first;
                right_bottom.second = it->first.second;
                count[RB]++;
            }
            if( it->second == (1<<LT) ) {
                if( count[LT] > 0 ) return false;
                left_top.first = it->first.first;
                left_top.second = it->first.second;
                count[LT]++;
            }
            if( it->second == (1<<RT) ) {
                if( count[RT] > 0 ) return false;
                right_top.first = it->first.first;
                right_top.second = it->first.second;
                count[RT]++;
            }
        }
        return (area_sum == ((right_bottom.first-left_bottom.first)*(left_top.second-left_bottom.second)) );
    }
};
