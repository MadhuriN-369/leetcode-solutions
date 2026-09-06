1class Solution {
2public:
3    int dp[1001][1001];
4    int solve(int i, int j, string &cur, string &s, string &t) {
5        if(i == s.size() || j == t.size()){
6            if(cur == t) return 1;
7            return 0;
8        }
9        if(cur == t) return 1;
10        if(cur.size() > t.size()) return 0;
11        if(dp[i][j] != -1) return dp[i][j];
12        int res = 0;
13        if(s[i] == t[j]){
14            cur.push_back(s[i]);
15            res = solve(i+1, j+1, cur, s, t);
16            cur.pop_back();
17        }
18        res += solve(i+1, j, cur, s, t);
19        return dp[i][j] = res;
20    }
21    int numDistinct(string s, string t) {
22        string cur = ;
23        memset(dp, -1, sizeof(dp));
24
25        return solve(0, 0, cur, s, t);
26    }
27};