1class Solution {
2public:
3    int solve(vector<int>&nums, int k){
4        if(k <= 0) return 0;
5        int right = 0, left = 0, ans = 0, n = nums.size();
6        unordered_map<int, int>mp;
7        while(right < n){
8            mp[nums[right]]++;
9            while(mp.size() > k){
10                mp[nums[left]]--;
11                if(mp[nums[left]] == 0){
12                    mp.erase(nums[left]);
13                }
14                left++;
15            }
16            ans += right-left+1;
17            right++;
18        }
19        return ans;
20    }
21    int subarraysWithKDistinct(vector<int>& nums, int k) {
22        return solve(nums, k)-solve(nums, k-1);
23    }
24};