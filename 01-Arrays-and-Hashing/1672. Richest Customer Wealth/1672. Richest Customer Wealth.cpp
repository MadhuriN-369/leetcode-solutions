1class Solution {
2public:
3    int maximumWealth(vector<vector<int>>& accounts) {
4        int maxi = 0;
5        for(int i = 0; i < accounts.size(); i++){
6            int sum = 0;
7            for(int j = 0; j < accounts[0].size(); j++){
8                sum += accounts[i][j];
9            }
10            maxi = max(maxi, sum);
11        }
12        return maxi;
13    }
14};