1class Solution {
2public:
3    bool getcost(int i, int val){
4        if(val == 1){
5            return !(i == 1);
6        }
7        if(val == 2){
8            return !(i == 3);
9        }
10        if(val == 3){
11            return !(i == 2);
12        }
13        return !(i == 0);
14    }
15    int minCost(vector<vector<int>>& grid) {
16        //cost, i, j
17        int m = grid.size(), n = grid[0].size();
18        priority_queue< tuple<int, int, int>, 
19        vector<tuple<int,int,int>>, greater<tuple<int,int,int>> >pq;
20        vector<vector<int>>dist(m ,vector<int>(n, INT_MAX));
21
22        pq.push({0, 0, 0});
23        dist[0][0] = 0;
24        int dx[] = {-1, 0, 1, 0};
25        int dy[] = {0, 1, 0, -1};
26        while(!pq.empty()){
27            auto [cost, row, col] = pq.top();
28            pq.pop();
29            if(row == m-1 && col == n-1) return cost;
30            for(int i = 0; i < 4; i++){
31                int nrow = row + dx[i];
32                int ncol = col + dy[i];
33                //i = 0 -> up
34                //i = 1 -> right
35                //i = 2 -> down
36                //i = 3 -> left
37
38                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && dist[nrow][ncol] > cost + getcost(i, grid[row][col])){
39                    pq.push({cost + getcost(i, grid[row][col]), nrow, ncol});
40                    dist[nrow][ncol] = cost + getcost(i, grid[row][col]);
41                }
42            }
43        }
44        return -1;
45    }
46};