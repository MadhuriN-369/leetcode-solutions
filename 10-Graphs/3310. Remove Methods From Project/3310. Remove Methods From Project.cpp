1constexpr int MAXN = 100005;
2
3class Solution {
4public:
5    vector<int> remainingMethods(int n, int k,
6                                 vector<vector<int>>& invocations) {
7        vector<vector<int>> edges(n);
8        vector<int> inDegree(n, 0);
9
10        bitset<MAXN> suspicious;
11
12        for (const auto& inv : invocations) {
13            edges[inv[0]].push_back(inv[1]);
14            inDegree[inv[1]]++;
15        }
16
17        queue<int> q;
18        q.push(k);
19
20        suspicious.set(k);
21
22        while (!q.empty()) {
23            int u = q.front();
24            q.pop();
25            for (int v : edges[u]) {
26                inDegree[v]--;
27
28                if (!suspicious.test(v)) {
29                    q.push(v);
30                    suspicious.set(v);
31                }
32            }
33        }
34
35        bool canRemoveAll = true;
36        vector<int> remaining;
37
38        for (int i = 0; i < n; i++) {
39            if (suspicious.test(i) && inDegree[i] > 0) {
40                canRemoveAll = false;
41                break;
42            } else if (!suspicious.test(i)) {
43                remaining.push_back(i);
44            }
45        }
46
47        if (!canRemoveAll) {
48            vector<int> allNodes(n);
49            iota(allNodes.begin(), allNodes.end(), 0);
50            return allNodes;
51        }
52
53        return remaining;
54    }
55};