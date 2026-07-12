1class Solution {
2public:
3    int lcs(string &s1, string &s2) {
4        int n = s1.size(), m = s2.size();
5        vector<int>cur(m+1, 0), prev(m+1, 0);
6        for(int i = 1; i <= n; i++) {
7            for(int j = 1; j <= m; j++) {
8                if(s1[i-1] == s2[j-1]){
9                    cur[j] = 1 + prev[j-1];
10                }
11                else{
12                    cur[j] = max(prev[j], cur[j-1]);
13                }
14            }
15            prev = cur;
16        }
17        return prev[m];
18    }
19    int minDistance(string word1, string word2) {
20        return word1.size() + word2.size() - 2*lcs(word1, word2);
21    }
22};