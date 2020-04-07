class Solution {
    String res;
    long res_val;
    long check_if_min(long old_diff, String n, String cand) {
        long cand_val = Long.parseLong(cand);
        long new_diff = string_val_diff(n, cand);
        if (new_diff < old_diff || (new_diff==old_diff && res_val > cand_val)) {
            res = new String(cand);
            res_val = cand_val;
            return new_diff;
        }
        return old_diff;
    }
    
    long string_val_diff(String n1, String n2) {
        return Math.abs(Long.parseLong(n1)-Long.parseLong(n2));
    }
    
    public String nearestPalindromic(String n) {
        if (n.length() == 0) return "";
        if (n.equals("0")) return "-1";
        if (n.length() == 1) return new StringBuilder(n).replace(0, 1, "" +(char)(n.charAt(0)-1)).toString();
 
        long diff = Long.MAX_VALUE;
        long tmp;
        int mid = n.length()/2;
        long n_val = Long.parseLong(n);
        long max_cand_val = (long)Math.pow(10, n.length())+1; // 100...01
        long min_cand_val = (long)Math.pow(10, n.length()-1)-1; // 99...9
        
        String cand1, cand2, cand3; 
        String half = (n.length()%2 == 0) ? n.substring(0, mid) : n.substring(0, mid+1);
        String half_minus = String.valueOf(Long.parseLong(half)-1);
        String half_plus = String.valueOf(Long.parseLong(half)+1);
        StringBuilder half_builder = new StringBuilder(half);
        StringBuilder half_m_builder = new StringBuilder(half_minus);
        StringBuilder half_p_builder = new StringBuilder(half_plus);
        if (n.length() % 2 == 0) { // even
            cand1 = half + half_builder.reverse().toString();
            cand2 = half_minus + half_m_builder.reverse().toString();
            cand3 = half_plus + half_p_builder.reverse().toString();
        }
        else { // odd
            cand1 = half + half_builder.reverse().toString().substring(1);
            cand2 = half_minus + half_m_builder.reverse().toString().substring(1);
            cand3 = half_plus + half_p_builder.reverse().toString().substring(1);
        }
        if (!n.equals(cand1))
            diff = check_if_min(diff, n, cand1);
        diff = check_if_min(diff, n, cand2);
        diff = check_if_min(diff, n, cand3);
        diff = check_if_min(diff, n, String.valueOf(min_cand_val));
        diff = check_if_min(diff, n, String.valueOf(max_cand_val));
        
        return res;
    }
}
