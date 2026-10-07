1class Solution {
2public:
3    vector<string> ans;
4    unordered_set<string> seen;
5    int minRemove;
6
7    void solve(int idx, int removed, int balance,
8               string &s, string &cur) {
9
10        // Too many removals
11        if (removed > minRemove)
12            return;
13
14        // Not enough characters left to reach minRemove
15        if (removed + (s.size() - idx) < minRemove)
16            return;
17
18        // End of string
19        if (idx == s.size()) {
20            if (removed == minRemove && balance == 0) {
21                if (!seen.count(cur)) {
22                    ans.push_back(cur);
23                    seen.insert(cur);
24                }
25            }
26            return;
27        }
28
29        char ch = s[idx];
30
31        // Normal characters cannot be removed
32        if (ch != '(' && ch != ')') {
33            cur += ch;
34            solve(idx + 1, removed, balance, s, cur);
35            cur.pop_back();
36            return;
37        }
38
39        // ----------------
40        // OPTION 1: KEEP
41        // ----------------
42        if (ch == '(') {
43            cur += ch;
44            solve(idx + 1, removed, balance + 1, s, cur);
45            cur.pop_back();
46        }
47        else { // ')'
48
49            // We cannot allow balance to become negative
50            if (balance > 0) {
51                cur += ch;
52                solve(idx + 1, removed, balance - 1, s, cur);
53                cur.pop_back();
54            }
55        }
56
57        // ----------------
58        // OPTION 2: REMOVE
59        // ----------------
60        solve(idx + 1, removed + 1, balance, s, cur);
61    }
62
63    vector<string> removeInvalidParentheses(string s) {
64
65        // Find minimum number of removals
66        stack<char> st;
67        minRemove = 0;
68
69        for (char ch : s) {
70
71            if (ch == '(') {
72                st.push(ch);
73            }
74            else if (ch == ')') {
75
76                if (st.empty())
77                    minRemove++;
78                else
79                    st.pop();
80            }
81        }
82
83        minRemove += st.size();
84
85        string cur = ;
86        solve(0, 0, 0, s, cur);
87
88        return ans;
89    }
90};