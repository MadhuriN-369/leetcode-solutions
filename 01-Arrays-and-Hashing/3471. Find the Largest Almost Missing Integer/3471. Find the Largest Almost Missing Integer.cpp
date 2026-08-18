1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        int n = nums.size();
5        int maxi = -1;
6        unordered_map<int,int>mp1;
7        for(int i = 0; i <= n-k && i < n; i++){
8            unordered_map<int,int>mp;
9            for(int j = i; j < i+k && j < n; j++){
10                mp[nums[j]]++;
11            }
12            for(auto it:mp){
13                mp1[it.first]++;
14            }
15        }
16        for(auto it:mp1){
17            if(it.second == 1) {
18                maxi = max(maxi, it.first);
19            }
20        }
21        return maxi;
22    }
23};