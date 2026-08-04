1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        vector<int>ans;
7        for(int i = 0; i < n-1; i++) {
8            if(nums[i+1] - nums[i] > 1){
9                for(int j = nums[i]+1; j < nums[i+1]; j++) ans.push_back(j);
10            }
11        }
12        return ans;
13    }
14};