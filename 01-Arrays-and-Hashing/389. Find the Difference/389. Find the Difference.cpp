1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        vector<int>freq1(26, 0);
5        vector<int>freq2(26, 0);
6        for(auto ch:s){
7            freq1[ch-'a']++;
8        }
9        for(auto ch:t){
10            freq2[ch-'a']++;
11        }
12        for(int i = 0; i < 26; i++){
13            if(freq1[i] != freq2[i]) return (char)('a' + i);
14        }
15        return 'a';
16    }
17};