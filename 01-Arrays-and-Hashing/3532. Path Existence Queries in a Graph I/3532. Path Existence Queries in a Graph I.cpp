1class DSU{
2public:
3    vector<int>parent, size;
4    DSU(int n) {
5        parent.resize(n);
6        size.resize(n, 1);
7        for(int i = 0; i < n; i++) {
8            parent[i] = i;
9        }
10    }
11    int findUpar(int u) {
12        if(u == parent[u]) return u;
13        return parent[u] = findUpar(parent[u]);
14    }
15    void unionBySize(int u, int v) {
16        int pu = findUpar(u);
17        int pv = findUpar(v);
18        if(pu == pv) return;
19        if(size[pu] >= size[pv]){
20            size[pu] += size[pv];
21            parent[pv] = pu;
22        }
23        else{
24            size[pv] += size[pu];
25            parent[pu] = pv;
26        }
27    }
28};
29class Solution {
30public:
31    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
32        DSU dsu(n);
33        vector<bool>answer;
34        int q = queries.size();
35        for(int i = 1; i < n; i++) {
36            if(abs(nums[i]-nums[i-1]) <= maxDiff) dsu.unionBySize(i, i-1);
37        }
38        for(int i = 0; i < q; i++){
39            int u = queries[i][0];
40            int v = queries[i][1];
41            if(dsu.findUpar(u) == dsu.findUpar(v)){
42                answer.push_back(true);
43            }
44            else{
45                answer.push_back(false);
46            }
47        }
48        return answer;
49    }
50};