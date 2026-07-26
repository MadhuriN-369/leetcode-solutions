1class Solution {
2public:
3    int minTimeToReach(vector<vector<int>>& grid) {
4        //time, i, j
5        int m = grid.size(), n = grid[0].size();
6        priority_queue<tuple<long long, int, int>, 
7        vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>> >pq;
8
9        vector<vector<long long>>dis(m, vector<long long>(n, LLONG_MAX));
10
11        pq.push({0, 0, 0});
12        dis[0][0] = 0;
13
14        int dx[] = {-1, 0, 1, 0};
15        int dy[] = {0, 1, 0, -1};
16
17        while(!pq.empty()){
18            auto [time, row, col] = pq.top();
19            pq.pop();
20            if(time > dis[row][col]) continue;
21            if(row == m-1 && col == n-1) return time;
22            
23            cout<<row<< <<col<<
;
24            for(int i = 0; i < 4; i++) {
25                int nrow = row + dx[i];
26                int ncol = col + dy[i];
27
28                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
29                    if(time >= grid[nrow][ncol]){
30                        if(dis[nrow][ncol] > time+1){
31                            pq.push({time+1, nrow, ncol});
32                            dis[nrow][ncol] = time+1;
33                        }
34                    }
35                    else if(dis[nrow][ncol] > grid[nrow][ncol]+1) {
36                        pq.push({grid[nrow][ncol] + 1, nrow, ncol});
37                        dis[nrow][ncol] = grid[nrow][ncol] +1;
38                    }
39                }
40            }
41        }
42
43        return -1;
44    }
45};