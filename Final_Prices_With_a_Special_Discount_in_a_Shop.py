class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        deque = []  
        ans = []
        discount = [0 for i in range(len(prices))]
        for idx, val in enumerate(prices):
            while len(deque) > 0 and val <= deque[-1][1]:
                discount[deque[-1][0]] = val
                deque.pop(-1)
            deque.append((idx,val))
        
        for i in range(len(prices)):
            ans.append(prices[i]-discount[i])
        
        return ans
