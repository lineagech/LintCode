class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        avail_servers = []
        occupied_servers = []
        load_num = [0 for i in range(k)]
        if k == 0:
            return []
        
        for i in range(k):
            avail_servers.append(i)
        
        ## Traveser the arrival
        for i, arrival_time in enumerate(arrival):
            ## pop available servers from occupied servers:
            while len(occupied_servers) > 0 and arrival_time >= occupied_servers[0][0]:
                #heappush(avail_servers, occupied_servers[0][1])
                insert_pos = bisect.bisect(avail_servers, occupied_servers[0][1])
                avail_servers.insert(insert_pos, occupied_servers[0][1])
                heappop(occupied_servers)
            
            ## Find the first valid server
            if len(avail_servers) == 0:
                continue

            idx = bisect_left(avail_servers, i % k)
            if idx == len(avail_servers):
                idx = 0
            
            load_num[avail_servers[idx]] += 1
            
            ## push to occupied list
            heappush(occupied_servers, (arrival_time+load[i], avail_servers[idx]))
            del avail_servers[idx]
        
        max_load = max(load_num)
        res = []
        for i in range(k):
            if load_num[i] == max_load:
                res.append(i)
        
        return res
        
