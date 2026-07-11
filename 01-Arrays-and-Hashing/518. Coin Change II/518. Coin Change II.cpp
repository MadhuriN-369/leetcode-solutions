1class Solution {
2public:
3    // int dp[301][5001];
4    // int solve(int idx, vector<int>&coins, int amount){
5    //     if(idx == coins.size()){
6    //         if(amount == 0) return 1;
7    //         return 0;
8    //     }
9    //     if(amount == 0) return 1;
10    //     if(dp[idx][amount] != -1) return dp[idx][amount];
11    //     //take | nottake
12    //     int nottake = solve(idx+1, coins, amount);
13    //     int take = 0;
14    //     if(amount >= coins[idx]) take = solve(idx, coins, amount-coins[idx]);
15    //     return dp[idx][amount] = take + nottake;
16    // }
17    int change(int target, vector<int>& coins) {
18        // memset(dp, -1, sizeof(dp));
19        int n = coins.size();
20        // vector<vector<long long>>dp(n+1, vector<long long>(target+1, 0));
21        vector<long long>prev(target+1, 0), cur(target+1, 0);
22        for(int i = 0; i <= n; i++) {
23            cur[0] = 1;
24        }
25        
26        for(int i = n-1; i >= 0; i--) {
27            for(int amount = 1; amount <= target; amount++){
28                unsigned long long nottake = prev[amount];
29                unsigned long long take = 0;
30                if(amount >= coins[i]) take = cur[amount-coins[i]];
31                cur[amount] = take + nottake;
32            }
33            prev = cur;
34        }
35        return prev[target];
36    }
37};