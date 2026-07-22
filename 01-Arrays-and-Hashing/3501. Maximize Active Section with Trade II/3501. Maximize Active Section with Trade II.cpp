1class SegmentTree {
2private:
3    int n;
4    vector<int> arr;
5    vector<int> seg;
6
7    void build(int p, int l, int r) {
8        if (l == r) {
9            seg[p] = arr[l];
10            return;
11        }
12
13        int mid = (l + r) >> 1;
14        build(p << 1, l, mid);
15        build(p << 1 | 1, mid + 1, r);
16        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
17    }
18
19    int _query(int p, int l, int r, int L, int R) {
20        if (L <= l && r <= R) {
21            return seg[p];
22        }
23
24        int mid = (l + r) >> 1;
25        int res = 0;
26        if (L <= mid) {
27            res = max(res, _query(p << 1, l, mid, L, R));
28        }
29        if (R > mid) {
30            res = max(res, _query(p << 1 | 1, mid + 1, r, L, R));
31        }
32
33        return res;
34    }
35
36public:
37    SegmentTree(const vector<int>& arr) : arr(arr) {
38        n = arr.size();
39        seg.resize(n << 2, 0);
40        build(1, 0, n - 1);
41    }
42
43    int query(int L, int R) {
44        if (L > R) {
45            return 0;
46        }
47
48        return _query(1, 0, n - 1, L, R);
49    }
50};
51
52class Solution {
53public:
54    vector<int> maxActiveSectionsAfterTrade(string s,
55                                            vector<vector<int>>& queries) {
56        int n = s.length();
57        int cnt1 = count(s.begin(), s.end(), '1');
58
59        vector<int> zeroBlocks;
60        vector<int> blockLeft;
61        vector<int> blockRight;
62
63        int i = 0;
64        while (i < n) {
65            int st = i;
66            while (i < n && s[i] == s[st]) {
67                i += 1;
68            }
69            if (s[st] == '0') {
70                zeroBlocks.push_back(i - st);
71                blockLeft.push_back(st);
72                blockRight.push_back(i - 1);
73            }
74        }
75
76        int m = zeroBlocks.size();
77        if (m < 2) {  // continuous 0 blocks less than 2 segments, return the
78                      // answer directly
79            return vector<int>(queries.size(), cnt1);
80        }
81
82        vector<int> tmpSum(m - 1);
83        for (int i = 0; i < m - 1; i++) {
84            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
85        }
86        SegmentTree seg(tmpSum);
87        vector<int> ans;
88
89        for (const auto& q : queries) {
90            int l = q[0], r = q[1];
91            int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
92                    blockRight.begin();
93            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
94                    blockLeft.begin() - 1;
95
96            // at most 1 continuous block of 0s within the substring
97            if (i > m - 1 || j < 0 || i >= j) {
98                ans.push_back(cnt1);
99                continue;
100            }
101            int firstLen = blockRight[i] - max(blockLeft[i], l) +
102                           1;  // actual length of the first consecutive block
103                               // of 0s in the substring
104            int lastLen = min(blockRight[j], r) - blockLeft[j] +
105                          1;  // actual length of the last consecutive block of
106                              // 0s in the substring
107            // exactly 2 consecutive 0 blocks within the substring
108            if (i + 1 == j) {
109                int bestGain = firstLen + lastLen;
110                ans.push_back(cnt1 + bestGain);
111                continue;
112            }
113
114            int val1 = firstLen + zeroBlocks[i + 1];
115            int val2 = zeroBlocks[j - 1] + lastLen;
116            int val3 = seg.query(i + 1, j - 2);
117            int bestGain = max({val1, val2, val3});
118            ans.push_back(cnt1 + bestGain);
119        }
120
121        return ans;
122    }
123};