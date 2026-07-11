1class Solution {
2public:
3    int longestCommonSubsequence(string text1, string text2) {
4        int n1 = text1.size(), n2 = text2.size();
5        vector<int>prev(n2+1, 0), cur(n2+1, 0);
6
7        for(int i = n1-1; i>= 0; i--){
8            for(int j = n2-1; j >= 0; j--) {
9                int res = 0;
10                if(text1[i] == text2[j]){
11                    res += 1 + prev[j+1];
12                }
13                res = max(res, prev[j]);
14                res = max(res, cur[j+1]);
15                cur[j] = res;
16            }
17            prev = cur;
18        }
19        return prev[0];
20    }
21};