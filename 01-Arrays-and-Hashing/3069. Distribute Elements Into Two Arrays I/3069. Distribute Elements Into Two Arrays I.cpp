1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        vector<int>arr1, arr2;
5        arr1.push_back(nums[0]);
6        arr2.push_back(nums[1]);
7        int n = nums.size();
8        for(int i = 2; i < n; i++) {
9            if(arr1.back() > arr2.back()){
10                arr1.push_back(nums[i]);
11            }
12            else{
13                arr2.push_back(nums[i]);
14            }
15        }
16        for(auto it: arr2) {
17            arr1.push_back(it);
18        }
19        return arr1;
20    }
21};