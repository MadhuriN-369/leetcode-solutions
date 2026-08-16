1class Solution {
2public:
3    bool solve(int cnt0, int cnt1, int cnt2, int turn, int mod) {
4        if(cnt0 == 0 && cnt1 ==0 && cnt2 == 0){
5            return false;
6        }
7        if(turn == 0){
8            bool res = false;
9            if(cnt0 > 0){
10                if(mod%3 != 0){
11                    res = res | solve(cnt0-1, cnt1, cnt2, 1, mod);
12                }
13            }
14            if(cnt1 > 0){
15                if((mod+1)%3 != 0){
16                    res = res | solve(cnt0, cnt1-1, cnt2, 1, (mod+1)%3);
17                }
18            }
19            if(cnt2 > 0){
20                if((mod + 2)%3 != 0){
21                    res = res | solve(cnt0, cnt1, cnt2-1, 1, (mod+2)%3);
22                }
23            }
24            return res;
25        }
26        else{
27            //bob's turn
28            bool res = true;
29            if(cnt0 > 0){
30                if(mod%3 != 0){
31                    res = res & solve(cnt0-1, cnt1, cnt2, 0, mod);
32                }
33            }
34            if(cnt1 > 0){
35                if((mod+1)%3 != 0){
36                    res = res & solve(cnt0, cnt1-1, cnt2, 0, (mod+1)%3);
37                }
38            }
39            if(cnt2 > 0){
40                if((mod + 2)%3 != 0){
41                    res = res & solve(cnt0, cnt1, cnt2-1, 0, (mod+2)%3);
42                }
43            }
44            return res;
45        }
46    }
47    bool stoneGameIX(vector<int>& stones) {
48        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
49        for(int i = 0; i < stones.size(); i++){
50            if(stones[i] % 3 == 0) cnt0++;
51            else if(stones[i]%3 == 1) cnt1++;
52            else cnt2++;
53        }
54        int mod = 0, turn = 0;
55        return solve(cnt0, cnt1, cnt2, turn, mod);
56    }
57};