1class Solution {
2public:
3    int dp[21][21][2];
4    int solve(int idx1, int idx2, int turn, vector<int>&nums) {
5        if(idx1 > idx2) return 0;
6        if(dp[idx1][idx2][turn] != -1) return dp[idx1][idx2][turn];
7        if(turn == 0){
8            return dp[idx1][idx2][turn] = max(nums[idx1] + solve(idx1+1, idx2, 1, nums), 
9                        nums[idx2] + solve(idx1, idx2-1, 1, nums));
10        }
11        return dp[idx1][idx2][turn] = min(solve(idx1+1, idx2, 0, nums), solve(idx1, idx2-1, 0, nums));
12    }
13    bool predictTheWinner(vector<int>& nums) {
14        int n = nums.size();
15        memset(dp, -1, sizeof(dp));
16        long long alice = solve(0, n-1, 0, nums);
17        long long bob = accumulate(nums.begin(), nums.end(), 0) - alice;
18        return alice >= bob;
19    }
20};