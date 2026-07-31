1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int n = ratings.size(); //number of children
5        vector<int>left = {1};
6        vector<int>right = {1};
7
8        for(int i = 1; i < n; i++){
9            if(ratings[i] > ratings[i-1]) left.push_back(left[i-1]+1);
10            else left.push_back(1);
11        }
12        int k = 0;
13        for(int i = n-2; i >= 0; i--){
14            if(ratings[i] > ratings[i+1]) right.push_back(right[k]+1);
15            else right.push_back(1);
16            k++;
17        }
18        int ans = 0;
19        reverse(right.begin(), right.end());
20        for(int i = 0; i < n; i++){
21            ans += max(left[i], right[i]);
22        }
23        return ans;
24    }
25};