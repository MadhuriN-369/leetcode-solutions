1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        stack<int>st;
5        vector<bool>inStack(26, 0);
6        vector<int>last(26, -1);
7        int n = s.size();
8        for(int i = 0; i < n; i++) {
9            last[s[i]-'a'] = i;
10        }
11        for(int i = 0; i < n; i++) {
12            if(inStack[s[i]-'a']) continue;
13            
14            while(!st.empty() && st.top() > s[i]-'a'){
15                if(last[st.top()] > i){
16                    inStack[st.top()] = 0;
17                    st.pop();
18                }
19                else break;
20            }
21            inStack[s[i]-'a'] = 1;
22            st.push(s[i]-'a');
23        }
24        string str = ;
25        while(!st.empty()){
26            str += (char) ('a' + st.top());
27            st.pop();
28        }
29        reverse(str.begin(), str.end());
30        return str;
31    }
32};