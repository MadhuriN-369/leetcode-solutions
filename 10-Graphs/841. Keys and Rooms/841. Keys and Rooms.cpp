1class Solution {
2public:
3    bool canVisitAllRooms(vector<vector<int>>& rooms) {
4        int n = rooms.size();
5        queue<int>q;
6        q.push({0});
7        vector<int>vis(n, 0);
8        vis[0] = true;
9        while(!q.empty()){
10            int node = q.front();
11            q.pop();
12            for(auto it:rooms[node]){
13                if(!vis[it]){
14                    vis[it] = true;
15                    q.push({it});
16                }
17            }
18        }
19
20        for(int i = 0; i < n; i++) {
21            if(!vis[i]) return false;
22        }
23        return true;
24    }
25};