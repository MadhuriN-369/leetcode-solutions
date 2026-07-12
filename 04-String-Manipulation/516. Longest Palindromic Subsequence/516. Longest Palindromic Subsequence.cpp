1class Solution {
2public:
3    int longestPalindromeSubseq(string s) {
4        string r = s;
5        reverse(r.begin(), r.end());
6        int n = s.size();
7        vector<int>cur(n+1, 0);
8        vector<int>prev(n+1, 0);
9        for(int i = 1; i <= n; i++) {
10            for(int j = 1; j <= n; j++) {
11                int res = 0;
12                if(s[i-1] == r[j-1]){
13                    res = 1 + prev[j-1];
14                }
15                else{
16                    res = max(prev[j] , cur[j-1]);
17                }
18                cur[j] = res;
19            }
20            prev = cur;
21        }
22        return prev[n];
23    }
24};