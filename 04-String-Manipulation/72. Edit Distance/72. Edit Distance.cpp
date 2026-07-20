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
24        vector<int>prev(m+1, 0);
25        vector<int>cur(m+1, 0);
26        for(int j = 0; j <= m; j++) {
27            prev[j] = m-j;
28        }
29        for(int i = n-1; i >= 0; i--) {
30            cur[m] = n-i;
31            for(int j = m-1; j >= 0; j--) {
32                int res = 1e8;
33                if(word1[i] == word2[j]) res = min(res, prev[j+1]);
34                
35                //insert
36                res = min(res, 1 + cur[j+1]);
37                //delete
38                res = min(res, 1 + prev[j]);
39                //replace
40                if(word1[i] != word2[j]) res = min(res, 1 + prev[j+1]);
41                cur[j] = res;
42            }
43            prev = cur;
44        }
45
46        return prev[0];
47    }
48};