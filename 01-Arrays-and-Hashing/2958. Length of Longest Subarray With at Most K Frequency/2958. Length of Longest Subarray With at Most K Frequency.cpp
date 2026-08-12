1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int left = 0, right = 0;
5        int n = nums.size();
6        unordered_map<int,int>mp;
7        int len = 0;
8        int maxfreq = 0;
9        int val = 0;
10        while(right < n) {
11            mp[nums[right]]++;
12            // maxfreq = max(maxfreq, mp[nums[right]]);
13            if(mp[nums[right]] > maxfreq){
14                val = nums[right];
15                maxfreq = max(maxfreq, mp[nums[right]]);
16            }
17            while(maxfreq > k){
18                mp[nums[left]]--;
19                if(val == nums[left]) maxfreq--;
20                if(mp[nums[left]] == 0) {
21                    mp.erase(nums[left]);
22                }
23                left++;
24            }
25            len = max(len, right-left+1);
26            right++;
27        }
28        return len;
29    }
30};