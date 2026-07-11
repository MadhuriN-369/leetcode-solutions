1class Solution {
2public:
3    int dp[301][5001];
4    int solve(int idx, vector<int>&coins, int amount){
5        if(idx == coins.size()){
6            if(amount == 0) return 1;
7            return 0;
8        }
9        if(amount == 0) return 1;
10        if(dp[idx][amount] != -1) return dp[idx][amount];
11        //take | nottake
12        int nottake = solve(idx+1, coins, amount);
13        int take = 0;
14        if(amount >= coins[idx]) take = solve(idx, coins, amount-coins[idx]);
15        return dp[idx][amount] = take + nottake;
16    }
17    int change(int amount, vector<int>& coins) {
18        memset(dp, -1, sizeof(dp));
19        return solve(0, coins, amount);
20    }
21};