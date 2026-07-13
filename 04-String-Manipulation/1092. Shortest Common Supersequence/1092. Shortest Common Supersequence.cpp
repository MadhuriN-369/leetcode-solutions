1class Solution {
2public:
3    string shortestCommonSupersequence(string s1, string s2) {
4        int n = s1.size(), m = s2.size();
5        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
6        for(int i = 1; i <= n; i++) {
7            for(int j = 1; j <= m; j++) {
8                if(s1[i-1] == s2[j-1]) {
9                    dp[i][j] = 1 + dp[i-1][j-1];
10                }
11                else{
12                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
13                }
14            }
15        }
16        //try to rebuild the string supersubsequence #shortest
17        int i = n, j = m;
18        string str = ;
19        while(i > 0 && j > 0) {
20            if(s1[i-1] == s2[j-1]){
21                str = str + s1[i-1];
22                i--;
23                j--;
24            }
25            else{
26                if(dp[i][j] == dp[i-1][j]){
27                    str = str + s1[i-1];
28                    i--;
29                }
30                else{
31                    str = str + s2[j-1];
32                    j--;
33                }
34            }
35        }
36        while(i > 0) {
37            str = str + s1[i-1];
38            i--;
39        }
40        while(j > 0) {
41            str = str + s2[j-1];
42            j--;
43        }
44        reverse(str.begin(), str.end());
45        return str;
46    }
47};