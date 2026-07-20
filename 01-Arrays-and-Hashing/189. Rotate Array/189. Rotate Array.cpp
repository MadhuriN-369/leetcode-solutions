1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        if(nums.size() == 1) return;
5        k = k % nums.size();
6        k = nums.size()-k;
7        reverse(nums.begin(), nums.begin()+k);
8        reverse(nums.begin()+k, nums.end());
9        reverse(nums.begin(), nums.end());
10
11    }
12};