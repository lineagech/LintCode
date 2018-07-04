class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        // do intialization if necessary
        this->_time = 0;
        this->_capacity = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        this->_time++;
        auto cache_it = cache.find(key);
        if( cache_it == cache.end() ) return -1;
        auto time_it = time_table.find(key);
        auto LRU_it = lookup_LRU.find( make_pair(time_it->second, key) );
        
        // update time
        time_it->second = this->_time;
        lookup_LRU.erase(LRU_it);
        lookup_LRU.insert( make_pair(this->_time, key) );
        
        // return value
        return cache_it->second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        this->_time++;
        auto cache_it = cache.find(key);
        if( cache_it != cache.end() )
        {
            auto LRU_it = lookup_LRU.find( make_pair(time_table[key], key) );
            lookup_LRU.erase(LRU_it);
        }
        else
        {
            if( this->_capacity == cache.size() )
            {
                // evict least recently used
                auto LRU_it_evict = lookup_LRU.begin();
                cache_it = cache.find( (*LRU_it_evict).second );
                auto time_it = time_table.find( (*LRU_it_evict).second );
                
                cache.erase(cache_it);
                time_table.erase(time_it);
                lookup_LRU.erase(LRU_it_evict);
            }
        }
        cache[key] = value;
        time_table[key] = this->_time;
        lookup_LRU.insert( make_pair(this->_time, key) );
    }
    
    unordered_map<int,int> cache;         // key, value
    unordered_map<int,int> time_table;    // key, _time
    multiset< pair<int,int> > lookup_LRU; // <_time, key>, will use _time to compare
    int _time;
    int _capacity;
};
