1class Solution {
2public:
3    bool sumGame(string num) {
4        int count = 0, first = 0;
5        int sum1 = 0, sum2 = 0;
6        for(int i = 0; i < num.size(); i++){
7            if(num[i] == '?') {
8                count++;
9                if(i < num.size()/2) first++;
10            }
11            else if(i < num.size()/2){
12                sum1 += num[i]-'0';
13            }
14            else sum2 += num[i]-'0';
15        }
16        int second = count-first;
17        if(count%2 == 1) return true;
18        if(2*(sum1-sum2) == 9*(second-first))
19            return false;
20        return true;
21    }
22};