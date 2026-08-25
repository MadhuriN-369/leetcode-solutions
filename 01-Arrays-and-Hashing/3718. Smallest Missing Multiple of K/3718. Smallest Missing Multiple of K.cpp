1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        unordered_set<int>st(nums.begin(), nums.end());
5        int val = k;
6        for(int i = 1; i <= 101; i++){
7            if(st.find(i*val) == st.end()) return i*val;
8        }
9        return -1;
10    }
11};