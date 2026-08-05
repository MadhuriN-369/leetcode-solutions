1class Solution {
2public:
3    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
4        if(vis[node]) return;
5        vis[node] = 1;
6        for(auto it: adj[node]){
7            if(!vis[it]) dfs(it, vis, adj);
8        }
9    }
10    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
11        if(invocations.size() == 0){
12            vector<int>ans;
13            for(int i = 0; i < n; i++){
14                if(i != k) ans.push_back(i);
15            }
16            return ans;
17        }
18        vector<vector<int>>adj(n);
19        for(auto it:invocations){
20            int u = it[0];
21            int v = it[1];
22            adj[u].push_back(v);
23        }
24        vector<int>vis(n, 0);
25        dfs(k, vis, adj);
26        vector<int>ans;
27        unordered_set<int>st;
28        for(auto it:invocations){
29            int u = it[0];
30            int v = it[1];
31            if(vis[v] == 1 && vis[u] != 1){
32                ans.clear();
33                for(int i = 0; i < n; i++) ans.push_back(i);
34                return ans;
35            }
36            if(vis[u] == 0 && vis[v] == 0){
37                if(st.find(u) == st.end()) ans.push_back(u);
38                if(st.find(v) == st.end()) ans.push_back(v);
39                st.insert(u);
40                st.insert(v);
41            }
42        }
43        for(int i = 0; i < n; i++){
44            if(st.find(i) == st.end() && !vis[i]) ans.push_back(i);
45        }
46        sort(ans.begin(), ans.end());
47        return ans;
48    }
49};