1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        stack<int>st;
5        for(int i = 0; i < tokens.size(); i++) {
6            string ch = tokens[i];
7            if((ch[0] == '-' && ch.length() != 1) || (ch[0] >= '0' && ch[0] <= '9')){
8                int num = stoi(ch);
9                st.push(num);
10            }
11            else{
12                //it must be an operator
13                if(ch == +){
14                    int num1 = st.top();
15                    st.pop();
16                    int num2 = st.top();
17                    st.pop();
18                    st.push(num1+num2);
19                }
20                else if(ch == -){
21                    int num1 = st.top();
22                    st.pop();
23                    int num2 = st.top();
24                    st.pop();
25                    st.push(num2-num1);
26                }
27                else if(ch == *){
28                    int num1 = st.top();
29                    st.pop();
30                    int num2 = st.top();
31                    st.pop();
32                    st.push(num1*num2);
33                }
34                else if(ch == /){
35                    int num1 = st.top();
36                    st.pop();
37                    int num2 = st.top();
38                    st.pop();
39                    st.push(num2/num1);
40                }
41            }
42        }
43        return st.top();
44    }
45};