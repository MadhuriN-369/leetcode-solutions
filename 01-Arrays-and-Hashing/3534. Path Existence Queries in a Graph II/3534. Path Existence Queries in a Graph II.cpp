1class Solution {
2public:
3    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
4        vector<int> sortedIdx(n);
5        iota(sortedIdx.begin(), sortedIdx.end(), 0);
6        sort(sortedIdx.begin(), sortedIdx.end(), [&](int a, int b){
7            return nums[a] < nums[b];
8        });
9        vector<int> pos(n);
10        for (int i = 0; i < n; i++) pos[sortedIdx[i]] = i;
11
12        // right[i] = furthest sorted-position reachable in ONE hop from position i
13        vector<int> right(n);
14        int j = 0;
15        for (int i = 0; i < n; i++) {
16            if (j < i) j = i;
17            while (j + 1 < n && nums[sortedIdx[j+1]] - nums[sortedIdx[i]] <= maxDiff) j++;
18            right[i] = j;
19        }
20
21        int LOG = 1;
22        while ((1 << LOG) < n) LOG++;
23        vector<vector<int>> up(LOG + 1, vector<int>(n));
24        up[0] = right;
25        for (int k = 1; k <= LOG; k++)
26            for (int i = 0; i < n; i++)
27                up[k][i] = up[k-1][up[k-1][i]];
28
29        vector<int> answer;
30        answer.reserve(queries.size());
31        for (auto &q : queries) {
32            int a = pos[q[0]], b = pos[q[1]];
33            if (a > b) swap(a, b);
34            if (a == b) { answer.push_back(0); continue; }
35
36            int cur = a, jumps = 0;
37            for (int k = LOG; k >= 0; k--) {
38                if (up[k][cur] < b) {
39                    cur = up[k][cur];
40                    jumps += (1 << k);
41                }
42            }
43            answer.push_back(right[cur] >= b ? jumps + 1 : -1);
44        }
45        return answer;
46    }
47};