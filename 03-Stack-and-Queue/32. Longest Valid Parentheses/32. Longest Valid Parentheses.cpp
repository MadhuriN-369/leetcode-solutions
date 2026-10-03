1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        stack<int> st;
5        st.push(-1);
6        int bestLength = 0;
7
8        for (int i = 0; i < s.size(); ++i)
9        {
10            if (s[i] == '(')
11            {
12                st.push(i);
13            }
14            else
15            {
16                st.pop();
17                if (st.empty())
18                {
19                    st.push(i);
20                }
21                else
22                {
23                    bestLength = max(bestLength, i - st.top());
24                }
25            }
26        }
27
28        return bestLength;
29    }
30};