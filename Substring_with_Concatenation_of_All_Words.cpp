class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> hash;
        vector<int> ans;
        if(words.size() == 0) return ans;
        for(auto word : words)
        {
            if(hash.find(word) == hash.end())
                hash[word] = 1;
            else
                hash[word]++;
        }
        
        int word_size = words[0].size();
        for(int i=0; i<word_size; i++)
        {
            unordered_map<string,int> sliding_window;
            int word_num = 0;
            for(int start = i; start < s.size(); start += word_size)
            {
                string curr_word = s.substr(start, word_size);
                if( hash.find(curr_word) != hash.end() )
                {
                    word_num++;
                    if( sliding_window.find(curr_word) == sliding_window.end() )
                        sliding_window[curr_word] = 1;
                    else
                        sliding_window[curr_word] += 1;
                    while(hash[curr_word] < sliding_window[curr_word])
                    {
                        string removed_string = s.substr(start-(word_num-1)*word_size, word_size);
                        sliding_window[removed_string]--;
                        word_num--;
                    }
                } 
                else
                {
                    sliding_window.clear();
                    word_num = 0;    
                }
                if(word_num == words.size())
                {
                    ans.emplace_back( start-(word_num-1)*word_size );
                }
            }
        }
        return ans;
    }
};
