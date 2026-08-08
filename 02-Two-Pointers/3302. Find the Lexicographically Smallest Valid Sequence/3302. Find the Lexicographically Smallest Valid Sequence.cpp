1class Solution {
2public:
3    vector<int> validSequence(string word1, string word2) {
4        int n = word1.length(), m = word2.length();
5        vector<int> last(m, -1);
6        int j = m - 1;
7        for (int i = n - 1; i >= 0; --i) {
8            if (j >= 0 && word1[i] == word2[j]) {
9                last[j] = i;
10                j -= 1;
11            }
12        }
13        vector<int> res;
14        int skip = 0;
15        j = 0;
16        for (int i = 0; i < n; ++i) {
17            if (j == m) break;
18            if (word1[i] == word2[j] ||
19                (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
20                skip += (word1[i] != word2[j] ? 1 : 0);
21                res.push_back(i);
22                j += 1;
23            }
24        }
25        return j == m ? res : vector<int>();
26    }
27};