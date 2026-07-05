1class Solution {
2public:
3    int arithmeticTriplets(vector<int>& nums, int diff) {
4        unordered_map<int,int>mp;
5        int count = 0;
6        for(auto it: nums) {
7            mp[it] = 1;
8        }
9        for(auto it: nums) {
10            if(mp.find(it+diff) != mp.end() && mp.find(it+diff*2) != mp.end()) count++;
11        }
12        return count;
13    }
14};