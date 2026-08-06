1class Solution {
2public:
3    string smallestNumber(string num, long long t) {
4        long long temp = t;
5        for (int i = 2; i <= 9; i++) {
6            while (temp % i == 0) {
7                temp /= i;
8            }
9        }
10        if (temp > 1) {
11            return -1;
12        }
13        int n = num.length();
14        vector<long long> rem(n + 1);
15        rem[0] = t;
16        int pos = n - 1;
17        for (int i = 0; i < n; i++) {
18            if (num[i] == '0') {
19                pos = i;
20                break;
21            }
22            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
23        }
24        if (rem[n] == 1) {
25            return num;
26        }
27
28        for (int i = pos; i >= 0; i--) {
29            while (++num[i] <= '9') {
30                long long tNow = rem[i] / gcd(rem[i], num[i] - '0');
31                int k = 9;
32                for (int j = n - 1; j > i; j--) {
33                    while (tNow % k) {
34                        k--;
35                    }
36                    tNow /= k;
37                    num[j] = '0' + k;
38                }
39                if (tNow == 1) {
40                    return num;
41                }
42            }
43        }
44
45        string ans;
46        for (int i = 9; i > 1; i--) {
47            while (t % i == 0) {
48                ans += '0' + i;
49                t /= i;
50            }
51        }
52        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
53        ranges::reverse(ans);
54        return ans;
55    }
56};