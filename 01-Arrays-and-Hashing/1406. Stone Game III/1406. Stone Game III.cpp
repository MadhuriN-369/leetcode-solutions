1class Solution {
2public:
3    int dp[50001];
4    int solve(int idx, vector<int>&stoneValue){
5        if(idx >= stoneValue.size()) return 0;
6        if(dp[idx] != -1) return dp[idx];
7        int res1 = stoneValue[idx] - solve(idx+1, stoneValue);
8        int res2 = INT_MIN;
9        if(idx < stoneValue.size()-1) res2 = stoneValue[idx] + stoneValue[idx+1] - solve(idx+2, stoneValue);
10        int res3 = INT_MIN;
11        if(idx < stoneValue.size()-2) res3 = stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] - solve(idx+3, stoneValue);
12
13        return dp[idx] = max(res1, max(res2, res3));
14    }
15    string stoneGameIII(vector<int>& stoneValue) {
16        int n = stoneValue.size();
17        if(n == 1) {
18            if(stoneValue[0] > 0) return Alice;
19            if(stoneValue[0] == 0) return Tie;
20            return Bob;
21        }
22        memset(dp, -1, sizeof(dp));
23        int res = solve(0, stoneValue);
24        if(res == 0) return Tie;
25        if(res > 0) return Alice;
26        return Bob;
27    }
28};