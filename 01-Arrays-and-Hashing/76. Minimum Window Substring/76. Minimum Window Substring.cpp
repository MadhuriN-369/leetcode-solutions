1class Solution {
2public:
3    bool isfreqsame(vector<int>freq1, vector<int>freq2){
4        for(int i = 0; i < 52; i++){
5            if(freq1[i] == 0) continue;
6            if(freq1[i] > freq2[i]) return false;
7        }
8        return true;
9    }
10    string minWindow(string s, string t) {
11        int l = 0, r = 0;
12        vector<int>freq(52, 0);
13        vector<int>inWindow(52, 0);
14        for(int i = 0; i < t.size(); i++){
15            if(isupper(t[i])) freq[t[i]-'A']++;
16            else freq[t[i]-'a'+26]++;
17        }
18        string minString = ;
19        while(r < s.size()){
20            if(isupper(s[r])) inWindow[s[r]-'A']++;
21            else inWindow[s[r]-'a'+26]++;
22
23            if(r-l+1 >= t.size()){
24                if(isfreqsame(freq, inWindow)){
25                    if(minString ==  || r-l+1 < minString.size()) minString = s.substr(l, r-l+1);
26                }
27            }
28
29            while(l <= r){
30                if(r-l+1 < t.size()) break;
31                if(r-l+1 >= t.size()){
32                    if(isfreqsame(freq, inWindow)){
33                        if(minString ==  || r-l+1 < minString.size()) minString = s.substr(l, r-l+1);
34                    }
35                }
36                if(isupper(s[l])){
37                    if(freq[s[l]-'A'] == 0 || inWindow[s[l]-'A'] > freq[s[l]-'A']) {
38                        inWindow[s[l]-'A']--;
39                    }
40                    else break;
41                }
42                else{
43                    if(freq[s[l]-'a'+26] == 0 || inWindow[s[l]-'a'+26] > freq[s[l]-'a'+26]){
44                        inWindow[s[l]-'a'+26]--;
45                    }
46                    else break;
47                }
48                
49
50                l++;
51            }
52
53            r++;
54        }
55        return minString;
56    }
57};