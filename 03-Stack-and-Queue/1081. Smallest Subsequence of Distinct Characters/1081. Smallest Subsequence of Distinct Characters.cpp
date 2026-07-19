1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        int n = s.size();
5        vector<int>last(26, -1);
6        for(int i = 0; i < n; i++) {
7            int c = (int)(s[i]-'a');
8            last[c] = i;
9        }
10        for(int i = 0; i < 26; i++) cout<<last[i]<< ;
11        cout<<endl;
12        cout<<here<<
;
13        stack<int>st;
14        vector<bool>inStack(26, 0);
15        string str = ;
16        for(int i = 0; i < n; i++){
17            cout<<here1<<
;
18            if(inStack[s[i]-'a']) continue;
19            if(st.empty()) {
20                inStack[s[i]-'a'] = 1;
21                st.push(s[i]-'a');
22                continue;
23            }
24            while(!st.empty() && st.top() > (s[i]-'a')){
25                if(last[st.top()] > i) {
26                    cout<<here2<<
;
27                    
28                    inStack[st.top()] = 0;
29                    st.pop();
30                }
31                else break;
32            }
33            st.push(s[i]-'a');
34            inStack[s[i]-'a'] = 1;
35        }
36        while(!st.empty()){
37            str += (char)('a'+st.top());
38            st.pop();
39        }
40        reverse(str.begin(), str.end());
41        return str;
42    }
43};