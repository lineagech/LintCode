class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        def ways(nodes):
            if len(nodes) <= 2:
                return 1
            root = nodes[0]
            l = [e for e in nodes[1:] if e < root]
            r = [e for e in nodes[1:] if e > root]
            return comb(len(l)+len(r), len(l)) * ways(l) * ways(r)
        
        return (ways(nums)-1) % (10**9 + 7)
