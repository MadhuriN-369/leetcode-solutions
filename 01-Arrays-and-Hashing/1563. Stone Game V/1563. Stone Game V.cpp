1class Solution {
2public:
3    int dp[501][501];
4    int solve(int start, int end, vector<int>&stoneValue){
5        if(start >= end) return 0;
6        if(dp[start][end] != -1) return dp[start][end];
7        int res = 0;
8        vector<int>left;
9        left.push_back(stoneValue[start]);
10        for(int i = start+1; i <= end; i++){
11            left.push_back(stoneValue[i] + left.back());
12        }
13        vector<int>right;
14        right.push_back(stoneValue[end]);
15        for(int j = end-1; j >= start; j--){
16            right.push_back(stoneValue[j] + right.back());
17        }
18        reverse(right.begin(), right.end());
19        for(int i = 1; i < left.size(); i++){
20            if(left[i-1] >= right[i]) {
21                res = max(res, right[i] + solve(start + i, end, stoneValue));
22            }
23            if(left[i-1] <= right[i]) res = max(res, left[i-1] + solve(start, start + i-1, stoneValue));
24        }
25        return dp[start][end] = res;
26    }
27    int stoneGameV(vector<int>& stoneValue) {
28        int n = stoneValue.size();
29        memset(dp, -1, sizeof(dp));
30        return solve(0, n-1, stoneValue);
31    }
32};