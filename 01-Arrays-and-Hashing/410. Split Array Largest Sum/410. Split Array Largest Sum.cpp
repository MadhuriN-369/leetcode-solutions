1class Solution {
2public:
3    bool possible(vector<int>& nums, int k, int mid) {
4        int sum = 0;
5        int count = 0;
6        for(int i = 0; i < nums.size(); i++) {
7            if(sum + nums[i] > mid) {
8                count++;
9                sum = 0;
10            }
11            sum += nums[i];
12        }
13        return count+1 <= k;
14    }
15    int splitArray(vector<int>& nums, int k) {
16        int low = *max_element(nums.begin(), nums.end());
17        int high = accumulate(nums.begin(), nums.end(), 0);
18        while(low < high) {
19            int mid = low + (high-low)/2;
20            if(possible(nums, k, mid)){
21                high = mid;
22            }
23            else low = mid+1;
24        }
25        return low;
26    }
27};