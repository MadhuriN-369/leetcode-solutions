1class Solution {
2public:
3    int minimumObstacles(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5
6        priority_queue<tuple<int, int,int>, 
7        vector<tuple<int, int,int>>, greater<tuple<int, int,int>>>pq;
8        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
9
10        pq.push({0, 0, 0});
11        dis[0][0] = 0;
12
13        int drow[] = {-1, 0, 1, 0};
14        int dcol[] = {0, 1, 0, -1};
15        while(!pq.empty()){
16            auto [cost, row , col] = pq.top();
17            pq.pop();
18
19            if(row == m-1 && col == n-1) return cost;
20            for(int i = 0; i < 4; i++){
21                int nrow = row + drow[i];
22                int ncol = col + dcol[i];
23
24                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && dis[nrow][ncol] > cost +grid[row][col]){
25                    pq.push({cost + grid[row][col], nrow, ncol});
26                    dis[nrow][ncol] = cost + grid[row][col];
27                }
28            }
29
30        }
31
32        return -1;
33    }
34};
35