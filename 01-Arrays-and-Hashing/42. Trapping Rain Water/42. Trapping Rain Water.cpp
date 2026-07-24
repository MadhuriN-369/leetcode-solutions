1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        vector<int>left(n+1, 0);
6        vector<int>right(n+1, 0);
7        left[0] = height[0];
8        for(int i = 1; i < n; i++){
9            left[i] = max(left[i-1], height[i]);
10        }
11        right[n-1] = height[n-1];
12        for(int i = n-1; i >= 0; i--) {
13            right[i] = max(right[i+1], height[i]);
14        }
15        int res = 0;
16        for(int i = 0; i < n; i++) {
17            res += min(left[i], right[i]) - height[i];
18        }
19        return res;
20    }
21};