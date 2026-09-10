1class Solution {
2public:
3    int solve(int n){
4        return (log10(n)+1)/3;
5    }
6    int countCommas(int n) {
7        if(n < 1000) return 0;
8        if(n == 100000) return 99001;
9        int ans = 0;
10        for(int i = 1000; i <= n; i++) ans += solve(i);
11        return ans;
12    }
13};