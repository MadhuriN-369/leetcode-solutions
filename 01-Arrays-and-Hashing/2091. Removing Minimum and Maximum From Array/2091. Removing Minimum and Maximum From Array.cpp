1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int mini_index = -1, mini = INT_MAX, maxi_index = -1, maxi = INT_MIN, n = nums.size();
5        if(n == 1) return 1;
6        for(int i = 0; i < nums.size(); i++) {
7            if(nums[i] > maxi){
8                maxi_index = i; 
9                maxi = nums[i];
10            }
11
12            if(nums[i] < mini){
13                mini_index = i;
14                mini = nums[i];
15            }
16
17        }
18        int res = INT_MAX;
19        res = min(res, mini_index +1 + n-maxi_index);
20        res = min(res, maxi_index +1 + n-mini_index);
21
22        res = min(res, max(mini_index, maxi_index)+1);
23        res = min(res, max(n-mini_index-1, n-1-maxi_index)+1);
24        return res;
25    }
26};