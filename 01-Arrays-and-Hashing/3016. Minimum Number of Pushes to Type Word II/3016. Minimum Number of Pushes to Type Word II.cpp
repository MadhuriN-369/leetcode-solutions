1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int>freq(26, 0);
5        for(auto ch: word){
6            freq[ch-'a']++;
7        }
8        sort(freq.begin(), freq.end(), greater<int>());
9        int ans = 0;
10        for(int i = 0; i < 26; i++){
11            if(freq[i] == 0) break;
12            if(i < 8) ans += freq[i];
13            else if(i < 16) ans += 2*freq[i];
14            else if(i < 24) ans += 3*freq[i];
15            else ans += 4*freq[i];
16            cout<<ans<<endl;
17        }
18        return ans;
19    }
20};