1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        for(int i = 0; i < nums.size(); i++){
5            string s = to_string(nums[i]);
6            int sum = 0;
7            for(auto ch:s){
8                sum += ch-'0';
9            }
10            if(sum == i) return i;
11        }
12        return -1;
13    }
14};