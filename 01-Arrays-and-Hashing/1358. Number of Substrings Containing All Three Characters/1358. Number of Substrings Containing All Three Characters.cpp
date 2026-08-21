1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n = s.size();
5        vector<int>last(3, -1);
6        int count = 0;
7        for(int i = 0; i < n; i++){
8            last[s[i]-'a'] = i;
9            if(last[0] >= 0 && last[1] >= 0 && last[2] >= 0){
10                int mini = min(last[0], min(last[1], last[2]));
11                count += mini+1;
12            }
13        }
14        return count;
15    }
16};