1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int cur = nums[0], maxi = nums[0];
5        for(int i = 1; i < nums.size(); i++){
6            cur = max(nums[i], cur+nums[i]);
7            maxi = max(cur, maxi);
8        }
9
10        return maxi;
11    }
12};