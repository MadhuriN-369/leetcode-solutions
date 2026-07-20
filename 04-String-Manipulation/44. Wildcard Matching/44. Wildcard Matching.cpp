1class Solution {
2public:
3    int dp[2001][2001];
4    bool solve(int i, int j, string &s, string &p) {
5        if(i == s.size() && j == p.size()) return true;
6        if(i == s.size()) {
7            for(; j < p.size(); j++){
8                if(p[j] != '*') return false;
9            }
10            return true;
11        }
12        if(j == p.size()) return false;
13        if(dp[i][j] != -1) return dp[i][j];
14        if(p[j] == '?') return dp[i][j] = solve(i+1, j+1, s, p);
15        bool res = false;
16        if(p[j] == '*') {
17            res = res | solve(i+1, j, s, p);
18            res = res | solve(i+1, j+1, s, p);
19            res = res | solve(i, j+1, s, p);
20            return dp[i][j] = res;
21        }
22        if(s[i] == p[j]) return dp[i][j] = solve(i+1, j+1, s, p);
23        return dp[i][j] = false;
24    }
25    bool isMatch(string s, string p) {
26        memset(dp, -1, sizeof(dp));
27        return solve(0, 0, s, p);
28    }
29};