1class Solution {
2public:
3    int dp[501][501][2];
4    int solve(int idx1, int idx2, bool turn, vector<int>&piles){
5        if(idx1 > idx2) return 0;
6        if(dp[idx1][idx2][turn] != -1) return dp[idx1][idx2][turn];
7        if(turn == 0){
8            //for alice
9            return dp[idx1][idx2][turn] = max(piles[idx1] + solve(idx1+1, idx2, 1, piles), 
10                        piles[idx2] + solve(idx1, idx2-1, 1, piles));
11        }
12        return dp[idx1][idx2][turn] = min(solve(idx1+1, idx2, 0, piles), solve(idx1, idx2-1, 0, piles));
13    }
14    bool stoneGame(vector<int>& piles) {
15        int n = piles.size();
16        memset(dp, -1, sizeof(dp));
17        int alice = solve(0, n-1, 0, piles); //turn = 0 for alice and 1 for bob
18        int bob = accumulate(piles.begin(), piles.end(), 0) - alice;
19        return alice > bob;
20    }
21};