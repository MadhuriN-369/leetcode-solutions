1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        unordered_set<int>st;
5        long long total = 0;
6        for(int i = 0; i < nums.size(); i++){
7            st.insert(nums[i]);
8            total += nums[i];
9        }
10        int sum = nums[0];
11        int length = 1;
12        for(int i = 1; i < nums.size(); i++){
13            if(nums[i] == nums[i-1] + 1){
14                length = i+1;
15                sum += nums[i];
16            }
17            else break;
18        }
19        for(int i = sum; i <= total+1; i++){
20            if(st.find(i) == st.end()) return i;
21        }
22        return -1;
23    }
24};