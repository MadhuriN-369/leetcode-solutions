1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int>answer;
5        vector<int>complete = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
6        for(int i = 0; i < complete.size(); i++) {
7            if(complete[i] >= low && complete[i] <= high){
8                answer.push_back(complete[i]);
9            }
10        }
11        return answer;
12    }
13};