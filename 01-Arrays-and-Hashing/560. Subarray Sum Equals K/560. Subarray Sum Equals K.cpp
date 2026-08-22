1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        unordered_map<long long, int>mp;
5        long long sum = 0;
6        int count = 0, n = nums.size();
7        mp[0] = 1;
8        for(int i = 0; i < n; i++) {
9            sum += nums[i];
10            if(mp.find(sum-k) != mp.end()){
11                count += mp[sum-k];
12            }
13            mp[sum]++;
14        }
15        return count;
16    }
17};