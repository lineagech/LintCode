from collections import defaultdict
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.h = defaultdict(list)
        

    def set(self, key: 'str', value: 'str', timestamp: 'int') -> 'None':
        self.h[key].append((timestamp,value))

    def get(self, key: 'str', timestamp: 'int') -> 'str':
        t_list = self.h[key]
        if t_list is None: return ""
        loc = bisect.bisect(t_list, (timestamp,chr(127)))

        return t_list[loc-1][1] if loc else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
