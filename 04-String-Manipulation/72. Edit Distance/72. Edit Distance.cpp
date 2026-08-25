1class Solution {
2public:
3    int dp[501][501];
4    int solve(int i, int j, string&s1, string &s2){
5        if(j >= s2.size()){
6            return s1.size()-i;
7        }
8        if(i >= s1.size()){
9            return s2.size()-j;
10        }
11        if(dp[i][j] != -1) return dp[i][j];
12        int res = 1e8;
13        if(s1[i] == s2[j]){
14            res = solve(i+1, j+1, s1, s2);
15        }
16        res = min(res, 1 + solve(i+1, j+1, s1, s2));
17        res = min(res, 1 + solve(i, j+1, s1, s2));
18        res = min(res, 1 + solve(i+1, j, s1, s2));
19        return dp[i][j] = res;
20    }
21    int minDistance(string word1, string word2) {
22        if(word1.size() == 0) return word2.size();
23        if(word2.size() == 0) return word1.size();
24        memset(dp, -1, sizeof(dp));
25        return solve(0, 0, word1, word2);
26    }
27};