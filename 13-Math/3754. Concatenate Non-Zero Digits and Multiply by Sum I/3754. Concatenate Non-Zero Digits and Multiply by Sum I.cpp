1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        if(n == 0) return 0;
5        int sum = 0;
6        string str = to_string(n);
7        string s = ;
8        for(auto it: str) {
9            if(it != '0'){
10                sum += (it-'0');
11                s += it;
12            }
13        }
14        long long num = stoi(s);
15        return num*sum;
16    }
17};