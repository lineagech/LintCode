class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        hash[val].push(nums.size()-1);
        return (hash[val].size() == 1);
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if( hash.find(val) == hash.end() || hash[val].empty() )
            return false;
        int swap_index = hash[val].top();
        hash[val].pop();
        
        if( swap_index != nums.size()-1 )
        {
            nums[swap_index] = nums.back();
            hash[nums.back()].pop();
            hash[nums.back()].push(swap_index);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[(rand() % nums.size())];
    }
    vector<int> nums;
    unordered_map<int,priority_queue<int>> hash;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
