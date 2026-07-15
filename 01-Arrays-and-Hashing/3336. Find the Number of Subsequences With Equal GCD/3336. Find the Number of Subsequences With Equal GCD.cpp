1class Solution {
2public:
3    const int MOD = (int)1e9 + 7;
4    long long dp[201][201][201];
5    int solve(int idx, int gcd1, int gcd2, vector<int>&nums) {
6        if(idx == nums.size()){
7            if(gcd1 == 0 || gcd2 == 0) return 0;
8            return gcd1 == gcd2 ? 1 : 0;
9        }
10        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];
11        //skip this index
12        int skip = solve(idx+1, gcd1, gcd2, nums);
13        //take it in seq1
14        int take1 = solve(idx+1, __gcd(gcd1, nums[idx]), gcd2, nums);
15        //take it in seq2
16        int take2 = solve(idx+1, gcd1, __gcd(gcd2, nums[idx]), nums);
17        return dp[idx][gcd1][gcd2] = (0LL + skip + take1 + take2)%MOD;
18    }
19    int subsequencePairCount(vector<int>& nums) {
20        // there are 3 possibilities, let's try to use recursion, to cover all the cases
21        memset(dp, -1, sizeof(dp));
22        return solve(0, 0, 0, nums);
23        //idx, gcd1, gcd2, nums
24    }
25};