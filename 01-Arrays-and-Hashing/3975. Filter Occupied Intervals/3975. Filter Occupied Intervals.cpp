1class Solution {
2public:
3    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
4        vector<vector<int>>merged;
5        vector<vector<int>>answer;
6        sort(occupiedIntervals.begin(), occupiedIntervals.end(), [&](vector<int>&a, vector<int>&b){
7            if(a[0] == b[0]) return a[1] > b[1];
8            return a[0] < b[0];
9        });
10        int count = 1;
11        int n = occupiedIntervals.size();
12        merged.push_back(occupiedIntervals[0]);
13        int last = occupiedIntervals[0][1];
14        
15        for(int i = 1; i < n; i++) {
16            if(occupiedIntervals[i][0] > last+1){
17                merged.push_back(occupiedIntervals[i]);
18                last = occupiedIntervals[i][1];
19            }
20            else{
21                last = max(merged.back()[1], occupiedIntervals[i][1]);
22                merged.back()[1] = last; 
23            }
24        }
25        //starting
26        int i;
27        for(i = 0; i < merged.size(); i++){
28            if(merged[i][1] < freeStart){
29                answer.push_back(merged[i]);
30            }
31            else {
32                break;
33            }
34        }
35        //overlapping ->so need to remove it off
36        for(; i < merged.size(); i++){
37            if(merged[i][0] <= freeStart-1) answer.push_back({merged[i][0], freeStart-1});
38            if(merged[i][1] > freeEnd){
39                answer.push_back({max(merged[i][0], freeEnd+1), merged[i][1]});
40                break;
41            }
42        }
43        i++;
44        for(; i < merged.size(); i++) {
45            answer.push_back(merged[i]);
46        }
47        return answer;
48    }
49};