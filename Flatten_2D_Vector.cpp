class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for( auto vec : vec2d ) {
            for( auto num : vec ) {
                (this->vec2d).push_back(num);
            }
        }
        this->curr_index = 0;
    }

    int next() {
        return vec2d[curr_index++];
    }

    bool hasNext() {
        if( curr_index >= vec2d.size() )
            return false;
        return true;
    }
    vector<int> vec2d;
    int curr_index;
};
