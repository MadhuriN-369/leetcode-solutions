1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>prefixGcd(n);
6        vector<int>mx(n);
7        mx[0] = nums[0];
8        for(int i = 1; i < n; i++) {
9            mx[i] = max(mx[i-1], nums[i]);
10        }
11        for(int i = 0; i < n; i++) {
12            prefixGcd[i] = __gcd(mx[i], nums[i]);
13        }
14        sort(prefixGcd.begin(), prefixGcd.end());
15        long long gcdsum = 0;
16
17        int st = 0, end = n-1;
18        while(st < end) {
19            gcdsum += __gcd(prefixGcd[st], prefixGcd[end]);
20            st++; end--;
21        }
22        return gcdsum;
23    }
24};