1class DSU{
2public:
3    vector<int>parent, size, edges;
4    DSU(int n) {
5        parent.resize(n);
6        size.resize(n, 1);
7        edges.resize(n, 0);
8        for(int i = 0; i < n; i++){
9            parent[i] = i;
10        }
11    }
12    int findUpar(int u){
13        if(u == parent[u]) return u;
14        return parent[u] = findUpar(parent[u]);
15    }
16    void unionBysize(int u, int v) {
17        int pu = findUpar(u), pv = findUpar(v);
18        if(pu == pv) {
19            edges[pu]++;
20            return;
21        }
22        if(size[pu] >= size[pv]){
23            size[pu] += size[pv];
24            parent[pv] = pu;
25            edges[pu] += edges[pv] + 1;
26        }
27        else{
28            size[pv] += size[pu];
29            parent[pu] = pv;
30            edges[pv] +=edges[pu]+1;
31        }
32    }
33};
34class Solution {
35public:
36    int countCompleteComponents(int n, vector<vector<int>>& edges) {
37        DSU dsu(n);
38        for(auto it: edges) {
39            int u = it[0], v = it[1];
40            //u - v
41            dsu.unionBysize(u, v);
42        }
43        int count = 0;
44        for(int i = 0; i < n; i++){
45            if(dsu.parent[i] == i) {
46                int edges = dsu.edges[i];
47                int nodes = dsu.size[i];
48                if(edges == nodes*(nodes-1)/2) count++;
49            }
50        }
51        return count;
52    }
53};