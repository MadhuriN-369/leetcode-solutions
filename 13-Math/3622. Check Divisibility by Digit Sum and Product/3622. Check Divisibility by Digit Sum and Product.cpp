1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        long long product = 1, sum = 0;
5        string s = to_string(n);
6        for(int i = 0; i < s.size(); i++){
7            int dig = s[i]-'0';
8            product = product*dig;
9            sum += dig;
10        }
11        if(n%(sum+product) == 0) return true;
12        return false;
13    }
14};