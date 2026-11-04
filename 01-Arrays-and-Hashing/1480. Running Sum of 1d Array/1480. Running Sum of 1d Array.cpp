1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4        vector<int>ans = {nums[0]};
5        for(int i = 1; i < nums.size(); i++){
6            ans.push_back(nums[i] + ans.back());
7        }
8        return ans;
9    }
10};