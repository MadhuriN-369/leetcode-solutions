1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;
5        for(auto it: s){
6            if(it == '(' || it == '{' || it == '[') st.push(it);
7            else if(st.empty()) return false;
8            else if(it == ')'){
9                if(st.top() != '(') return false;
10                st.pop(); 
11            }
12            else if(it == ']'){
13                if(st.top() != '[') return false;
14                st.pop(); 
15            }
16            else if(it == '}'){
17                if(st.top() != '{') return false;
18                st.pop(); 
19            }
20        }
21        return st.empty();
22    }
23};