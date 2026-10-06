1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int count = 0;
5        stack<char>st;
6        for(auto ch:s){
7            if(ch == '(') st.push(ch);
8            else{
9                if(st.empty()) count++;
10                else st.pop();
11            }
12        }
13        count += st.size();
14        return count;
15    }
16};