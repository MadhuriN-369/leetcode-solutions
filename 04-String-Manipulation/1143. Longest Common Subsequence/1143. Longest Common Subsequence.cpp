1class Solution {
2public:
3    int solve(int i, int j, string &text1, string &text2, vector<vector<int>>&dp) {
4        if(i == text1.size() || j == text2.size()){
5            return 0;
6        }
7        if(dp[i][j] != -1) return dp[i][j];
8        int res = 0;
9        if(text1[i] == text2[j]){
10            res += 1 + solve(i+1, j+1, text1, text2, dp);
11        }
12        res = max(res, solve(i+1, j, text1, text2, dp));
13        res = max(res, solve(i, j+1, text1, text2, dp));
14        return dp[i][j] = res;
15    }
16    int longestCommonSubsequence(string text1, string text2) {
17        int n1 = text1.size(), n2 = text2.size();
18        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
19
20        for(int i = n1-1; i>= 0; i--){
21            for(int j = n2-1; j >= 0; j--) {
22                int res = 0;
23                if(text1[i] == text2[j]){
24                    res += 1 + dp[i+1][j+1];
25                }
26                res = max(res, dp[i+1][j]);
27                res = max(res, dp[i][j+1]);
28                dp[i][j] = res;
29            }
30        }
31        return dp[0][0];
32    }
33};