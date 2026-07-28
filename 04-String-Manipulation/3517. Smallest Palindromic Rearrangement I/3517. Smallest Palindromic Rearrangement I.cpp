1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n = s.size();
5        if(n == 1) return s;
6        string left = ;
7        string mid = ;
8        vector<int>freq(26, 0);
9        for(int i = 0; i < s.size(); i++) {
10            freq[s[i]-'a']++;
11        }
12
13        for(int i = 0; i < 26; i++){
14            left = left + string(freq[i]/2, 'a'+i);
15            if(freq[i]%2 == 1) {
16                if(mid == ) mid = (char)('a'+i);
17            }
18        }
19        string right = left;
20        reverse(right.begin(), right.end());
21        return left+mid+right;
22    }
23};