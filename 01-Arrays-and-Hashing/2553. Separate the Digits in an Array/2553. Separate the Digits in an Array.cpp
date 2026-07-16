1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int>answer;
5        for(auto it: nums) {
6            string str = to_string(it);
7            for(auto ch: str) {
8                answer.push_back(ch-'0');
9            }
10        }
11        return answer;
12    }
13};