1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.rbegin(), nums.rend());
5        int n = nums.size();
6        return max(nums[0]*nums[1]*nums[2], (nums[n-1] < 0 ? nums[0]*nums[n-1]*nums[n-2] : 0));
7    }
8};