class Solution {
public:
    int compress(vector<char>& chars) {
        char now_char;
        int new_idx = 0;
        int continuous_count = 0;
        int ans = 0;
        
        if( chars.size() == 0 ) return 1;
        
        for( int i=0; i<chars.size(); i++ )
        {
            if( continuous_count == 0 || (now_char != chars[i]) ) {
                if( continuous_count != 0 ) 
                {
                    ans += 1; // this char
                    chars[new_idx++] = now_char;
                    string str_count = to_string(continuous_count); // this char the number of occurence
                    if( continuous_count > 1 )
                    {                    
                        ans += str_count.size(); 
                        for( int j=0; j<str_count.size(); j++ )
                            chars[new_idx++] = str_count[j];
                    }
                }
                now_char = chars[i];
                continuous_count = 1;
            }
            else {
                continuous_count++;   
            }
        }
        if( continuous_count != 0 ) 
        {
            ans += 1; // this char
            chars[new_idx++] = now_char;
            string str_count = to_string(continuous_count); // this char the number of occurence
            if( continuous_count > 1 )
            {
                ans += str_count.size(); 
                for( int j=0; j<str_count.size(); j++ )
                    chars[new_idx++] = str_count[j];
            }
        }
        
        return ans;
    }
};
