class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) {
        // do intialization if necessary
        this->capacity = capacity;
        this->Time = 0;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        this->Time++;
        auto c_it = cache.find(key);
        int new_occur = 1;
        if( (c_it) != cache.end() )
        {
            new_occur = c_it->second.second+1;
            auto lookup_it = occur_lookup.find( make_pair(make_pair(c_it->second.second, time_table[key]), key) );
            auto time_it = time_table.find( key );
            cache.erase(c_it);
            occur_lookup.erase(lookup_it);
            time_table.erase(time_it);
        }
        else
        {
            if( cache.size() == this->capacity )
            {
                // find least used one
                auto lookup_it = occur_lookup.begin();        // O(logn)
                //cerr <<(*lookup_it).second<<endl;
                auto cache_it = cache.find( (*lookup_it).second );   // O(1)
                auto time_it = time_table.find((*lookup_it).second);
                occur_lookup.erase( lookup_it );              // O(logn)
                cache.erase( cache_it );                      // O(1)
                time_table.erase( time_it );

            }
        }
        cache[key] = make_pair( value, new_occur );               // O(1)
        time_table[key] = this->Time;
        occur_lookup.insert( make_pair(make_pair(new_occur, this->Time), key) );
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        // update used number
        this->Time++;
        auto cache_it = cache.find( key ); // O(1)
        if( cache_it == cache.end() ) return -1;
        auto key_time = time_table[key];
        auto occur_it = occur_lookup.find( make_pair( make_pair(cache_it->second.second, key_time), 
                                                      key) ); // O(logn)
        cache_it->second.second++;                                    
        occur_lookup.erase( occur_it ); //O(logn)
        occur_lookup.insert( make_pair( make_pair(cache_it->second.second, this->Time), 
                                        cache_it->first) ); // O(logn)
        time_table[key] = this->Time;
        return cache_it->second.first; 
    }
    multiset<pair<pair<int,int>,int>> occur_lookup; /*<occurence, Time, key>*/
    unordered_map<int,unsigned int> time_table; // key, time
    unordered_map<int,pair<int,int>> cache; // key, (value, occurence)
    int capacity;
    unsigned int Time;

};
