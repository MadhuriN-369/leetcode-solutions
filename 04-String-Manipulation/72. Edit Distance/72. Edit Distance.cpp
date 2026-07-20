1class Solution {
2public:
3    int solve(int i, int j, string &word1, string &word2, vector<vector<int>>&dp) {
4        if(j == word2.size()){
5            return word1.size()-i;
6        }
7        if(i == word1.size()){
8            return word2.size()-j;
9        }
10        if(dp[i][j] != -1) return dp[i][j];
11        int res = 1e8;
12        if(word1[i] == word2[j]) res = min(res, solve(i+1, j+1, word1, word2, dp));
13        
14        //insert
15        res = min(res, 1 + solve(i, j+1, word1, word2, dp));
16        //delete
17        res = min(res, 1 + solve(i+1, j, word1, word2, dp));
18        //replace
19        if(word1[i] != word2[j]) res = min(res, 1 + solve(i+1, j+1, word1, word2, dp));
20        return dp[i][j] = res;
21    }
22    int minDistance(string word1, string word2) {
23        int n = word1.size(), m = word2.size();
24        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
25        return solve(0, 0, word1, word2, dp);
26    }
27};