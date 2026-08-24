1class Solution {
2public:
3    int solve(int idx, vector<int>&arr, vector<int>&dp){
4        if(idx == arr.size()-1) {
5            return arr[idx];
6        }
7        if(dp[idx] != INT_MIN) return dp[idx];
8        int take = arr[idx] - solve(idx+1, arr, dp);
9        int nottake = solve(idx+1, arr, dp);
10        return dp[idx] = max(take, nottake);
11    }
12    int stoneGameVIII(vector<int>& stones) {
13        vector<int>pre;
14        int n = stones.size();
15        pre.push_back(stones[0]);
16        for(int i = 1; i < stones.size(); i++) {
17            pre.push_back(pre.back()+stones[i]);
18        }
19        vector<int>dp(n+1, INT_MIN);
20        return solve(1, pre, dp);
21    }
22};