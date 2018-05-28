class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        // write your code here
        if(n <= 0) return "";
        deque<string> curr;
        for(int i=1; i<=n; i++)
            curr.push_back(to_string(i));
        
        while(curr.size())
        {
            deque<string> next;
            int curr_size = curr.size();
            for(int i=0; i<curr_size/2; i++)
            {
                string front = curr.front();
                string back = curr.back();
                next.push_back("("+front+","+back+")");
                curr.pop_front();
                curr.pop_back();
            }
            if(next.size() == 1)
                return next.front();
            curr = next;
        }
        
    }
};
