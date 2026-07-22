1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int n = s.size();
5        int count1 = 0, count = 0;
6        vector<int>zeroblocks;
7        s = '1' + s + '1';
8        for(int i = 0; i <= n+1; i++) {
9            if(s[i] == '0') count++;
10            else{
11                if(i != 0 && i != n+1) count1++;
12                if(count != 0) zeroblocks.push_back(count);
13                count = 0;
14            }
15        }
16        if(zeroblocks.size() < 2) return count1;
17        int best = 0;
18        for(int i = 0; i < zeroblocks.size()-1; i++) {
19            best = max(best, zeroblocks[i] + zeroblocks[i+1]);
20        }
21        return best+count1;
22    }
23};