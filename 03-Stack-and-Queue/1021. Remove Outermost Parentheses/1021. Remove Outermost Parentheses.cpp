1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        int sum = 0;
5        int last = 0;
6        string res = ;
7        for(int i = 0; i < s.size(); i++){
8            if(s[i] == '('){
9                sum++;
10            }
11            else{
12                sum--;
13                if(sum == 0) {
14                    res = res + s.substr(last+1, i-last-1);
15                    last = i+1;
16                }
17            }
18        }
19        return res;
20    }
21};