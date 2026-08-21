1class Solution {
2public:
3    long long lcm(long long a, long long b) {
4        return (a/__gcd(a, b))*b;
5    }
6    long long countMultiples(long long X, vector<int>&coins){
7        int n = coins.size();
8        long long count = 0;
9        for(int mask = 1; mask < (1<<n); mask++){
10            long long curlcm = 1;
11            int bits = 0;
12            bool overflow = false;
13            for(int i = 0; i < n; i++) {
14                if(mask & (1<<i)){
15                    bits++;
16                    curlcm = lcm(curlcm, coins[i]);
17                    if(curlcm > X){
18                        overflow = true;
19                        break;
20                    }
21                }
22            }
23
24            if(overflow) continue;
25            if(bits%2 == 1){
26                count += X/curlcm;
27            }
28            else count -= X/curlcm;
29        }
30        return count;
31    }
32    long long findKthSmallest(vector<int>& coins, int k) {
33        sort(coins.begin(), coins.end());
34        long long low = 1, high = 1LL*coins[0]*k, answer = 0;
35        while(low <= high){
36            long long mid = low + (high-low)/2;
37
38            if(countMultiples(mid, coins) >= k){
39                answer = mid;
40                high = mid-1;
41            }
42            else low = mid+1;
43        }
44        return answer;
45    }
46};