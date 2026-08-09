1class Solution {
2public:
3    int dp[101][201][2];
4    int solve(int idx, int m, bool turn, vector<int>&piles) {
5        if(idx >= piles.size()) return 0;
6        if(dp[idx][m][turn] != -1) return dp[idx][m][turn];
7        if(turn == 0){
8            //Alice turn, can go from 1 to 2*m elements
9            long long res = 0;
10            long long sum = piles[idx];
11            for(int i = 1; i <= min(2*m, (int)(piles.size())-idx); i++){
12                res = max(res, sum + solve(idx+i, max(m, i), 1, piles));
13                if(idx+i < piles.size()) sum += piles[idx+i]; //getting overflow here, what to do?
14            }
15            return dp[idx][m][turn] = res;
16        }
17        else{
18            //bob's turn
19            int res = INT_MAX;
20            for(int i = 1; i <= min(2*m, (int)(piles.size())-idx); i++){
21                res = min(res, solve(idx+i, max(m, i), 0, piles));
22            }
23            return dp[idx][m][turn] = (res == INT_MAX ? 0: res);
24        }
25    }
26    int stoneGameII(vector<int>& piles) {
27        int n = piles.size();
28        if(n == 1) return piles[0];
29        memset(dp, -1, sizeof(dp));
30        return solve(0, 1, 0, piles);
31    }
32};