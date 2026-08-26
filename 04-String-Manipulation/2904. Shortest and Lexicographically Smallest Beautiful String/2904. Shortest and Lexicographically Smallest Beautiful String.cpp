1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        int shortest = 1e8;
5        vector<string>vec;
6        for(int i = 0; i < s.size(); i++) {
7            int count = 0;
8            for(int j = i; j < s.size(); j++){
9                if(s[j] == '1') count++;
10                if(count == k) {
11                    // vec.push_back(s.substr(i, j-i+1));
12                    shortest = min(shortest, j-i+1);
13                }
14            }
15        }
16        for(int i = 0; i < s.size(); i++) {
17            int count = 0;
18            for(int j = i; j < s.size(); j++){
19                if(s[j] == '1') count++;
20                if((count == k) && (j-i+1 == shortest)) {
21                    vec.push_back(s.substr(i, j-i+1));
22                    // shortest = min(shortest, j-i+1);
23                }
24            }
25        }
26        if(vec.empty()) return ;
27        sort(vec.begin(), vec.end());
28        return vec[0];
29    }
30};