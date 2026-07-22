1class LRUCache:
2
3    def __init__(self, capacity: int):
4        self.capacity = capacity
5        self.cache = OrderedDict()
6
7    def get(self, key: int) -> int:
8        if key not in self.cache:
9            return -1
10        self.cache.move_to_end(key)
11        return self.cache[key]
12
13    def put(self, key: int, value: int) -> None:
14        if key in self.cache:
15            self.cache.move_to_end(key)
16        self.cache[key] = value
17        if(len(self.cache) > self.capacity):
18            self.cache.popitem(last = False)
19        
20
21
22
23# Your LRUCache object will be instantiated and called as such:
24# obj = LRUCache(capacity)
25# param_1 = obj.get(key)
26# obj.put(key,value)