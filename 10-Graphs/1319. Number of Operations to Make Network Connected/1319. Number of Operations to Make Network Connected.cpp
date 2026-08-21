1class DSU{
2public:
3    vector<int>parent, size;
4    DSU(int n){
5        parent.resize(n);
6        size.resize(n, 1);
7        for(int i = 0; i < n; i++) parent[i] = i;
8    }
9    int findUpar(int u) {
10        if(parent[u] == u) return u;
11        return parent[u] = findUpar(parent[u]);
12    }
13    void unionBySize(int u, int v) {
14        int pu = findUpar(u), pv = findUpar(v);
15        if(pu == pv) return;
16        if(size[pu] >= size[pv]) {
17            parent[pv] = pu;
18            size[pu] += size[pv];
19        }
20        else{
21            parent[pu]=pv;
22            size[pv]+=size[pu];
23        }
24    }
25};
26class Solution {
27public:
28    int makeConnected(int n, vector<vector<int>>& connections) {
29        DSU dsu(n);
30        int extra = 0;
31        for(auto it: connections) {
32            int u = it[0], v = it[1];
33            if(dsu.findUpar(u) == dsu.findUpar(v)) extra++;
34            else dsu.unionBySize(u, v);
35        }
36        int no_of_components = 0;
37        for(int i = 0; i < n; i++) {
38            if(dsu.parent[i] == i) no_of_components++;
39        }
40        // cout<<extra<< <<no_of_components-1<<endl;
41        int needed = no_of_components-1;
42        if(needed <= extra) return needed;
43        return -1;
44    }
45};