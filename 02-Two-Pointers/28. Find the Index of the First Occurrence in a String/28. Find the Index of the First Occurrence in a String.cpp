1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if(haystack.find(needle) != string::npos) return haystack.find(needle);
5        return -1;
6    }
7};