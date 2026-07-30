1class Solution {
2public:
3    int minimumPushes(string word) {
4        unordered_set<int>st;
5        for(auto ch: word){
6            st.insert(ch-'a');
7        }
8        int n = st.size();
9        if(n <= 8) return n;
10        if(n < 16) return 8 + (n%8)*2;
11        if(n < 24) return 24 + (n%8)*3;
12        return 48 + (n%8)*4;
13    }
14};