1class Solution {
2public:
3    vector<int> longestRepeating(string s, string queryCharacters,
4                                 vector<int>& queryIndices) {
5        int n = s.size();
6        vector<int> pre(4 * n), suf(4 * n), maxLen(4 * n);
7        vector<char> leftChar(4 * n), rightChar(4 * n);
8
9        auto pushUp = [&](int u, int l, int r) {
10            int mid = (l + r) >> 1;
11            int leftLen = mid - l + 1, rightLen = r - mid;
12            int left = u << 1, right = u << 1 | 1;
13            leftChar[u] = leftChar[left];
14            rightChar[u] = rightChar[right];
15            pre[u] = pre[left];
16            if (pre[left] == leftLen && rightChar[left] == leftChar[right]) {
17                pre[u] = pre[left] + pre[right];
18            }
19            suf[u] = suf[right];
20            if (suf[right] == rightLen && rightChar[left] == leftChar[right]) {
21                suf[u] = suf[right] + suf[left];
22            }
23            maxLen[u] = max(maxLen[left], maxLen[right]);
24            if (rightChar[left] == leftChar[right]) {
25                maxLen[u] = max(maxLen[u], suf[left] + pre[right]);
26            }
27        };
28
29        function<void(int, int, int)> build = [&](int u, int l, int r) {
30            if (l == r) {
31                pre[u] = 1;
32                suf[u] = 1;
33                maxLen[u] = 1;
34                leftChar[u] = s[l];
35                rightChar[u] = s[l];
36                return;
37            }
38            int mid = (l + r) >> 1;
39            build(u << 1, l, mid);
40            build(u << 1 | 1, mid + 1, r);
41            pushUp(u, l, r);
42        };
43
44        function<void(int, int, int, int, char)> update =
45            [&](int u, int l, int r, int pos, char ch) {
46                if (l == r) {
47                    leftChar[u] = ch;
48                    rightChar[u] = ch;
49                    return;
50                }
51                int mid = (l + r) >> 1;
52                if (pos <= mid) {
53                    update(u << 1, l, mid, pos, ch);
54                } else {
55                    update(u << 1 | 1, mid + 1, r, pos, ch);
56                }
57                pushUp(u, l, r);
58            };
59
60        build(1, 0, n - 1);
61        int k = queryIndices.size();
62        vector<int> ans(k);
63        for (int i = 0; i < k; i++) {
64            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
65            ans[i] = maxLen[1];
66        }
67        return ans;
68    }
69};