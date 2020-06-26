class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        full_lake_dict = defaultdict(int)
        dry_chances = 0
        res = [None] * len(rains)
        pending_index = []
        
        if len(rains) == 0:
            return []
        
        for i, k in enumerate(rains):
            if k == 0:
                dry_chances += 1
                pending_index.append(i)
            else:
                if k in full_lake_dict:
                    if dry_chances <= 0:
                        return []
                    else:
                        pos = bisect_right(pending_index, full_lake_dict[k])
                        if pos == len(pending_index):
                            return []
                        res[pending_index[pos]] = k
                        pending_index.pop(pos)
                        dry_chances -= 1
                        full_lake_dict.pop(k)
                else:
                    if i > 0 and rains[i-1] == k:
                        return []
                    full_lake_dict[k] = i
                res[i] = -1
        
        for idx in pending_index:
            res[idx] = 1
        
        return res
