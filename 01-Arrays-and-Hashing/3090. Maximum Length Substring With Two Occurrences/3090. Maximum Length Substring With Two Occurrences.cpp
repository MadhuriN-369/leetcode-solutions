1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        int left = 0, right = 0, n = s.size();
5        unordered_map<char, int>mp;
6        int maxfreq = 0, max_index = 0, len = 0;
7        while(right < n){
8            mp[s[right]]++;
9            // maxfreq = max(maxfreq, mp[s[right]]);
10            if(mp[s[right]] > maxfreq){
11                max_index = right;
12                maxfreq = mp[s[right]];
13            }
14            while(left <= right && maxfreq > 2){
15                mp[s[left]] = mp[s[left]] - 1;
16                if(mp[s[left]] == 0){
17                    mp.erase(s[left]);
18                }
19                if(s[max_index] == s[left]) maxfreq--;
20                left++;
21            }
22            len = max(len, right-left+1);
23            right++;
24        }
25        return len;
26    }
27};