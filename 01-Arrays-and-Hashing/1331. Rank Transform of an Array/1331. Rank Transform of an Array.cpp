1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int>temp(arr.begin(), arr.end());
5        sort(temp.begin(), temp.end());
6        unordered_map<int, vector<int>>mp;
7        for(int i = 0; i < arr.size(); i++) {
8            mp[arr[i]].push_back(i);
9        }
10        int count = 0;
11        for(int i = 0; i < temp.size(); i++) {
12            if(count == 0 || mp.find(temp[i]) != mp.end()){
13                count++;
14                for(auto it: mp[temp[i]]){
15                    arr[it] = count;
16                }
17                mp.erase(temp[i]);
18            }
19        }
20        return arr;
21    }
22};