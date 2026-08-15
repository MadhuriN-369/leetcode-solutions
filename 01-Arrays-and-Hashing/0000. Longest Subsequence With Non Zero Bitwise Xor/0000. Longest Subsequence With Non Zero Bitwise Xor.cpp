1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int n = nums.size();
5        int xor1 = 0;
6        for(int i = 0; i < nums.size(); i++){
7            xor1 ^= nums[i];
8        }
9        if(xor1 > 0) return n;
10        xor1 = 0;
11        for(int i = 0; i < nums.size(); i++) {
12            xor1 ^= nums[i];
13            if(xor1 != 0) return n-1;
14        }
15        return 0;
16    }
17};