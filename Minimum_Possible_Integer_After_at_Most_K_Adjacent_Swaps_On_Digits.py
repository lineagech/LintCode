class Solution:
    class bid_tree:
        def __init__ (self, n):
            self.n = n+1
            self.sum = [0 for i in range(self.n)]
            
        def update(self, idx: int, val: int):
            idx += 1
            while (idx < self.n):
                self.sum[idx] += val
                idx += idx & -idx
        
        def query(self, idx: int):
            idx += 1
            res = 0
            while (idx > 0):
                res += self.sum[idx]
                idx -= idx & -idx
            return res
    
    def minInteger(self, num: str, k: int) -> str:
        n = len(num)
        num_pos = defaultdict(list)
        for pos, c in enumerate(num):
            num_pos[int(c)].append(pos)
        
        w_tree = self.bid_tree(n)
        has_moved = [False for i in range(n)]
        cost = 0
        ans = ""
        
        while cost < k and len(ans) < n:
            for d in range(0, 10): # traverse all digits
                if len(num_pos[d]) == 0:
                    continue
                pos = num_pos[d][0]
                # get the cost
                n_cost = pos - w_tree.query(pos-1)

                if cost + n_cost > k:
                    continue;
                num_pos[d].pop(0)
                cost += n_cost
                # update the bid tree
                w_tree.update(pos,1)
                ans += str(d)
                has_moved[pos] = True
                break;
                
        for pos, c in enumerate(num):
            if not has_moved[pos]:
                ans += c
        
        return ans
                
            
            
        
        
        
