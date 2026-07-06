1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b){
5            if(a[0] == b[0]) return a[1] > b[1];
6            return a[0] < b[0];
7        });
8        int last = intervals[0][1];
9        int count = 1;
10        for(int i = 1; i < intervals.size(); i++) {
11            if(intervals[i][0] > last || intervals[i][1] > last){
12                count++;
13                last = intervals[i][1];
14            }
15        }
16        return count;
17    }
18};