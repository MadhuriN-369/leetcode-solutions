1class DSU{
2public:
3    vector<int>parent, size, total_edges;
4    DSU(int n) {
5        parent.resize(n);
6        size.resize(n, 1);
7        total_edges.resize(n, 0);
8        for(int i = 0; i < n; i++){
9            parent[i] = i;
10        }
11    }
12
13    int findUpar(int u) {
14        if(parent[u] == u) return u;
15        return parent[u] = findUpar(parent[u]);
16    }
17
18    void unionBySize(int u, int v) {
19        int pu = findUpar(u);
20        int pv = findUpar(v);
21        if(pu == pv){
22            total_edges[pu]++;
23            return;
24        }
25        if(size[pu] >= size[pv]) {
26            total_edges[pu] += total_edges[pv]+1;
27            size[pu] += size[pv];
28            parent[pv] = pu;
29        }
30        else{
31            total_edges[pv] += total_edges[pu]+1;
32            size[pv] += size[pu];
33            parent[pu] = pv;
34        }
35    }
36};
37class Solution {
38public:
39    int countCompleteComponents(int n, vector<vector<int>>& edges) {
40        DSU dsu(n);
41
42        for(auto it: edges) {
43            int u = it[0];
44            int v = it[1];
45            //u->v v->u
46            dsu.unionBySize(u, v);
47        }
48        int count = 0;
49        for(int i = 0; i < n; i++) {
50            if(dsu.parent[i] == i) {
51                int m = dsu.size[i];
52                int edge = dsu.total_edges[i];
53                if((m*(m-1)/2) == edge) count++;
54            }
55        }
56        return count;
57    }
58};