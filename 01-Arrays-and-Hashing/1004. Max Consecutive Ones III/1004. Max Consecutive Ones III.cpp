1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int left = 0, right = 0, n = nums.size();
5        int count = 0, maxlen = 0;
6        while(right < n){
7            if(nums[right] == 0) count++;
8            while(left <= right && count > k){
9                if(nums[left] == 0) count--;
10                left++;
11            }
12            maxlen = max(maxlen, right-left+1);
13            right++;
14        }
15        return maxlen;
16    }
17};