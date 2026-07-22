1class Solution {
2public:
3    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
4        if(source == target) return 0;
5        int n = routes.size();
6        vector<int>vis(n, 0);
7        unordered_map<int, vector<int>>mp;
8        for(int k = 0; k < routes.size(); k++){
9            for(auto i: routes[k]){
10                mp[i].push_back(k);
11            }
12        }
13        
14        queue<pair<int,int>>q;
15        //route, no of buses
16        for(auto it: mp[source]){
17            vis[it] = true;
18            q.push({it, 1});
19        }
20
21        while(!q.empty()){
22            int node = q.front().first;
23            int dis = q.front().second;
24            q.pop();
25            for(auto it: routes[node]){
26                if(it == target) return dis;
27                for(auto i: mp[it]){
28                    if(!vis[i]){
29                        vis[i] = true;
30                        q.push({i, dis+1});
31                    }
32                }
33            }
34        }
35        return -1;
36    }
37};