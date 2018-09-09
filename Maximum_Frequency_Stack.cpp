class FreqStack {
public:
    FreqStack() {
        stacks.resize(2, stack<int>());
        max_freq = 0;
    }
    
    void push(int x) {
        auto it = freq_hash.find(x);
        if( it == freq_hash.end() ) {
            freq_hash[x] = 1;
        }
        else {
            freq_hash[x] += 1;
        }
        max_freq = max(max_freq, freq_hash[x]);
        if( stacks.size() <= freq_hash[x] ) {
            stacks.emplace_back(stack<int>());
        }
        stacks[freq_hash[x]].push(x);
    }
    
    int pop() {
        int result = stacks[max_freq].top();
        stacks[max_freq].pop();
        freq_hash[result]--;
        while( stacks[max_freq].empty() ) max_freq--;
        return result;
    }
    int max_freq;
    vector<stack<int>> stacks;
    unordered_map<int,int> freq_hash;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
