1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int left = 0, right = 0, maxfreq = 0;
5        int n = s.size(), maxlen = 0;
6        char maxch;
7        unordered_map<char, int>mp;
8
9        while(right < n) {
10            mp[s[right]]++;
11            // maxfreq = max(maxfreq, mp[s[right]]);
12            if(mp[s[right]] > maxfreq) {
13                maxch = s[right];
14                maxfreq = mp[s[right]];
15            }
16
17            while(maxfreq > 1){
18                mp[s[left]]--;
19                if(mp[s[left]] < 0) {
20                    mp.erase(s[left]);
21                }
22                if(maxch == s[left]) maxfreq--;
23                left++;
24            }
25
26            maxlen = max(maxlen, right-left+1);
27            right++;
28        }
29        return maxlen;
30    }
31};