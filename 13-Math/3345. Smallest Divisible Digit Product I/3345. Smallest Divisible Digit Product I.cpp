1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        for(int num = n; num <= 100; num++){
5            int N = num;
6            long long prod = 1;
7            while(N > 0){
8                int rem = N%10;
9                prod *= rem;
10                N /= 10;
11            }
12            if(prod % t == 0) return num;
13        }
14        return 0;
15    }
16};