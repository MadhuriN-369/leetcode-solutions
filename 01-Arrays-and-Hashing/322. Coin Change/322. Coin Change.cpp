1class Solution {
2public:
3    int dp[13][10001];
4    int solve(int idx, vector<int>&coins, int amount) {
5        if(idx == coins.size()){
6            if(amount != 0) return 1e8;
7            return 0;
8        }
9        if(dp[idx][amount] != -1) return dp[idx][amount];
10        int nottake = 0 + solve(idx+1, coins, amount);
11        int take = 1e8;
12        if(coins[idx] <= amount) take = 1 + solve(idx, coins, amount-coins[idx]);
13        return dp[idx][amount] = min(take, nottake);
14    }
15    int coinChange(vector<int>& coins, int amount) {
16        memset(dp, -1, sizeof(dp));
17        int res = solve(0, coins, amount);
18        return res == 1e8 ? -1 : res;
19    }
20};