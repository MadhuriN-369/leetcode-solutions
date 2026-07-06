1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int m = matrix.size(), n = matrix[0].size();
5        int top = 0, bottom = m-1, left = 0, right = n-1;
6        vector<int>answer;
7        while(top <= bottom && left <= right) {
8            for(int j = left; j <= right; j++) {
9                answer.push_back(matrix[top][j]);
10            }
11            top++;
12            for(int i = top; i <= bottom; i++){
13                answer.push_back(matrix[i][right]);
14            }
15            right--;
16            if(top <= bottom){
17                for(int j = right; j >= left; j--){
18                    answer.push_back(matrix[bottom][j]);
19                }
20                bottom--;
21            }
22            if(left <= right) {
23                for(int i = bottom; i >= top; i--) {
24                    answer.push_back(matrix[i][left]);
25                }
26                left++;
27            }
28        }
29        return answer;
30    }
31};