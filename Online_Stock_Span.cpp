class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if( stack.size() == 0 ) 
        {
            stack.push(make_pair(price,1));
            return 1;
        }
        int total = 1;
        while( stack.size() > 0 && price >= stack.top().first )
        {
            total += stack.top().second;
            stack.pop();
        }
        stack.push(make_pair(price,total));
        return total;
    }
    std::stack<pair<int,int>> stack; /*(value, span)*/
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
