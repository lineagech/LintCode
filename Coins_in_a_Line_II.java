public class Solution {
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int[] values) {
        return dp(values,0)>dp(values,1) || dp(values,0)>dp(values,2);
    }
    private int dp(int[] values, int i)
    {
        if( hash.containsKey(i) ) return hash.get(i);
        if( i >= values.length ) return 0;
        else if( i == values.length-1 ) {
            hash.put(i, values[values.length-1]);
        }
        else if( i == values.length-2 ) 
            hash.put(i, Math.max( values[values.length-1], 
                             values[values.length-2]+values[values.length-1] ));
        else {
            hash.put(i, Math.max( 
                Math.min(values[i]+dp(values,i+2),values[i]+dp(values,i+3)),
                Math.min(values[i]+values[i+1]+dp(values,i+3), values[i]+values[i+1]+dp(values,i+4)) ));
        }
        return hash.get(i);
    }
    HashMap<Integer,Integer> hash = new HashMap<Integer,Integer>();
}
