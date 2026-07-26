1class Solution {
2public:
3    int shortestPath(vector<vector<int>>& grid, int k) {
4        // steps, row, col, obstacles_elminated
5        int m = grid.size(), n = grid[0].size();
6        priority_queue<tuple<int, int, int, int>, 
7        vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>pq;
8
9        vector<vector<vector<int>>>dis(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
10
11        pq.push({0, 0, 0, 0});
12        dis[0][0][0] = 0;
13
14        int dx[] = {-1, 0, 1, 0};
15        int dy[] = {0, 1, 0, -1};
16
17        while(!pq.empty()){
18            auto[steps, row, col, obs] = pq.top();
19            pq.pop();
20
21            if(dis[row][col][obs] < steps) continue;
22            if(row == m-1 && col == n-1) return steps;
23
24            for(int i = 0; i < 4; i++) {
25                int nrow = row + dx[i];
26                int ncol = col + dy[i];
27
28                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
29                    if(grid[nrow][ncol] == 1 && obs +1 <= k && dis[nrow][ncol][obs+1] > steps+1){
30                        pq.push({steps+1, nrow, ncol, obs+1});
31                        dis[nrow][ncol][obs+1] = steps+1;
32                    }
33                    else if(grid[nrow][ncol] == 0 && dis[nrow][ncol][obs] > steps+1){
34                        pq.push({steps+1, nrow, ncol, obs});
35                        dis[nrow][ncol][obs] = steps+1;
36                    }
37                }
38            }
39        }
40        return -1;
41    }
42};