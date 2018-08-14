class Solution {
public:
    /**
     * @param numerator: a integer
     * @param denominator: a integer
     * @return: return a string
     */
    string fractionToDecimal(int numerator, int denominator) {
        // write your code here
        unordered_map<long long, int> hash;
        long long nu = (long long)numerator;
        long long deno = (long long)denominator;
        long long int_part = nu/deno;
        string str_frac_part = ".";
        
        string str_int_part = to_string(int_part);
        nu -= int_part*denominator;
        nu *= 10;
        // nu should < deno
        while( nu != 0 )
        {   
            int record_idx = str_frac_part.size();
            while( nu < deno )
            {
                str_frac_part += "0";
                nu *= 10;
            }
            if( hash.find(nu) != hash.end() )
            {
                str_frac_part.insert(hash[nu], "(");
                str_frac_part.insert(str_frac_part.size(), ")");
                return (str_int_part+str_frac_part);
            }
            else hash[nu] = record_idx;
            
            long long tmp = nu/deno;
            str_frac_part += to_string(tmp);
            nu -= tmp*deno;
            nu *= 10;
        }
        if( str_frac_part.size() == 1 ) return str_int_part;
        return (str_int_part+str_frac_part); 
    }
};
