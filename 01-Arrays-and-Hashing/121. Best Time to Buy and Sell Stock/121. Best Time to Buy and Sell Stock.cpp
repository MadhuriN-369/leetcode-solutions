1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int mini = prices[0];
5        int n = prices.size();
6        int answer = 0;
7        for(int i = 1; i < n; i++){
8            answer = max(answer, prices[i]-mini);
9            mini = min(mini, prices[i]);
10        }
11        return answer;
12    }
13};