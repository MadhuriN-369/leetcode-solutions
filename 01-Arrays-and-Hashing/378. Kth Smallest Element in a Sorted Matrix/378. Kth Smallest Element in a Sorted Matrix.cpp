1class Solution {
2public:
3    int kthSmallest(vector<vector<int>>& matrix, int k) {
4        vector<int>arr;
5        int n = matrix.size();
6        for(int i = 0; i < n; i++) {
7            for(int j = 0; j < n; j++) {
8                arr.push_back(matrix[i][j]);
9            }
10        }
11        sort(arr.begin(), arr.end());
12        return arr[k-1];
13    }
14};