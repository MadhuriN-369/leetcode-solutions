1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int maxi = *max_element(nums.begin(), nums.end());
5        int mini = *min_element(nums.begin(), nums.end());
6        return __gcd(maxi, mini);
7    }
8};