1class Solution {
2public:
3    int hardestWorker(int n, vector<vector<int>>& logs) {
4        unordered_map<int,int>mp;
5        int time = 0;
6        for(int i = 0; i < logs.size(); i++){
7            mp[logs[i][0]] = max(mp[logs[i][0]], logs[i][1] - time);
8            time = logs[i][1];
9        }
10        int maxi_id = -1, maxi = 0;
11        for(auto it: mp){
12            if(it.second > maxi){
13                maxi = it.second;
14                maxi_id = it.first;
15            }
16            else if(it.second == maxi){
17                maxi_id = min(maxi_id, it.first);
18            }
19        }
20        return maxi_id;
21    }
22};