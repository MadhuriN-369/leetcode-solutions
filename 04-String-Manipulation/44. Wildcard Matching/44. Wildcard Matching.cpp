1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        int n = s.size(), m = p.size();
5        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
6        dp[n][m] = 1;
7        for(int j = m-1; j >= 0; j--){
8            dp[n][j] = (p[j] == '*') && dp[n][j+1];
9        }
10        for(int i = n-1; i >= 0; i--){
11            for(int j = m-1; j >= 0; j--) {
12                if(p[j] == '?') {
13                    dp[i][j] = dp[i+1][j+1];
14                    continue;
15                }
16                bool res = false;
17                if(p[j] == '*') {
18                    res = res | dp[i+1][j];
19                    res = res | dp[i][j+1];
20                    dp[i][j] = res;
21                    continue;
22                }
23                if(s[i] == p[j]) {
24                    dp[i][j] = dp[i+1][j+1];
25                    continue;
26                }
27                dp[i][j] = false;
28            }
29        }
30        return dp[0][0];
31    }
32};