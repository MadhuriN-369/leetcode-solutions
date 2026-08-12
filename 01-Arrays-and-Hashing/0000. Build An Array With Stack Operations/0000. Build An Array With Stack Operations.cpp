1class Solution {
2public:
3    vector<string> buildArray(vector<int>& target, int n) {
4        vector<string>ans;
5        unordered_set<int>st;
6        int maxi = 0;
7        for(int i = 0; i < target.size(); i++){
8            st.insert(target[i]);
9            maxi = max(maxi, target[i]);
10        }
11        for(int i = 1; i <= maxi; i++){
12            if(st.find(i) == st.end()){
13                ans.push_back(Push);
14                ans.push_back(Pop);
15            }
16            else{
17                ans.push_back(Push);
18            }
19        }
20        return ans;
21    }
22};