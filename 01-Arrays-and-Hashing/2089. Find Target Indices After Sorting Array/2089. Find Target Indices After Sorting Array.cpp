1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5        vector<int>tar;
6        for(int i = 0; i < nums.size(); i++){
7            if(nums[i] == target){
8                tar.push_back(i);
9            }
10        }
11        return tar;
12    }
13};