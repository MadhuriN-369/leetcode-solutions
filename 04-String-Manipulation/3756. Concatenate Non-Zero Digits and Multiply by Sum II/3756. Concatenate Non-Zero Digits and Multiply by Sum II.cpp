1class Solution {
2public:
3    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
4        int n = s.size();
5        const long long MOD = 1e9+7;
6        vector<int>sum(n+1, 0);
7        vector<int>cnt(n+1, 0);
8        vector<long long>num(n+1, 0);
9        vector<int>res;
10        int m = queries.size();
11        for(int i = 0; i < n; i++) {
12            int d = s[i]-'0';
13            cnt[i+1] = cnt[i] + ((d == 0) ? 0 : 1);
14            num[i+1] = ((d == 0) ? num[i] : (num[i]*10 + d)%MOD);
15            sum[i+1] = sum[i] + d;
16        }
17        vector<long long>pow10(100001, 1);
18        for(int i = 1; i < 100001; i++) {
19            pow10[i] = pow10[i-1]*10%MOD;
20        }
21        for(int i = 0; i < m; i++) {
22            int l = queries[i][0];
23            int r = queries[i][1]+1;
24            long long x = (num[r] - num[l]*pow10[cnt[r]-cnt[l]]%MOD + MOD) %MOD;
25            long long summy = sum[r]-sum[l];
26            long long result = (x*summy)%MOD;
27            res.push_back(result);
28        }
29        return res;
30    }
31};