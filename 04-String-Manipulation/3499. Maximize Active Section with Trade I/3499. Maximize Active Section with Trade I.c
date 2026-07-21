1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int n = s.size();
5        s = '1'+s+'1';
6        int count1 = 0, count = 0;
7        vector<int>vec;
8        for(int i = 1; i < n+2; i++) {
9            if(s[i] == '0') count++;
10            else{
11                if(count != 0) vec.push_back(count);
12                if(i != n+1) count1++;
13                count = 0;
14            }
15        }
16        if(vec.size() < 2) return count1;
17        int bestgain = 0;
18        for(int i = 0; i < vec.size()-1; i++){
19            bestgain = max(bestgain, vec[i] + vec[i+1]);
20        }
21        return bestgain + count1;
22    }
23};