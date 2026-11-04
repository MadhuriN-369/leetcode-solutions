1class Solution {
2public:
3    int numIdenticalPairs(vector<int>& nums) {
4        int count = 0;
5        for(int i = 0; i < nums.size(); i++){
6            for(int j = 0; j < i; j++){
7                if(nums[i] == nums[j]) count++;
8            }
9        }
10        return count;
11    }
12};