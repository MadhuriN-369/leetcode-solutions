1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        return __gcd(n*n+n, n*n);
5    }
6};