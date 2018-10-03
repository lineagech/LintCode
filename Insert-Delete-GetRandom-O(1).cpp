class RandomizedSet {
public:
    RandomizedSet() {
        // do intialization if necessary
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        // write your code here
        if(hash.find(val)!=hash.end()){
            return false;
        }
        
        nums.push_back(val);
        hash[val]=nums.size();
        
        return true;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        // write your code here
        if(hash.find(val)==hash.end()){
            return false;
        }
        int last=nums.back();
        hash[last]=hash[val];
        nums[hash[val]]=last;
        
        hash.erase(val);
        nums.pop_back();
        
        return true;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        // write your code here
        return rand()%nums.size();
    }
    vector<int> nums;
    unordered_map<int,int> hash;
    
};
