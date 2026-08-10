1
2class Solution {
3public:
4    int dp[100001][2];
5    bool solve(int n, bool turn){
6        if(n == 0){
7            if(turn == 1) return true;
8            return false;
9        }
10        if(dp[n][turn] != -1) return dp[n][turn];
11        bool res = false;
12        if(turn == 0){
13            for(int i = 1; i*i <= n; i++){
14                res = res | solve(n-i*i, !turn);
15            }
16        }
17        else{
18            res = true;
19            for(int i = 1; i*i <= n; i++){
20                res = res & solve(n-i*i, !turn);
21            }
22        }
23        return dp[n][turn] = res;
24    }
25    bool winnerSquareGame(int n) {
26        memset(dp, -1, sizeof(dp));
27        return solve(n, 0);
28    }
29};