1class Solution {
2public:
3    bool uniqueOccurrences(vector<int>& arr) {
4        unordered_map<int,int>freq;
5        unordered_set<int>st;
6        for(auto it:arr){
7            freq[it]++;
8        }
9        for(auto it:freq){
10            if(st.find(it.second) != st.end()) return false;
11            st.insert(it.second);
12        }
13        return true;
14    }
15};