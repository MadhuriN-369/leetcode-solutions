1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
15            return {-1, -1};
16        }
17        vector<int>ans;
18        vector<int>critical;
19        ListNode* temp = head->next;
20        int prev = head->val;
21        int idx = 1;
22        while(temp->next != nullptr){
23            if(temp->val > prev && temp->val > temp->next->val){
24                critical.push_back(idx);
25            }
26            if(temp->val < prev && temp->val < temp->next->val){
27                critical.push_back(idx);
28            }
29            prev = temp->val;
30            temp = temp->next;
31            idx++;
32        }
33        if(critical.size() < 2) return {-1, -1};
34        int mini = INT_MAX;
35        for(int i = 0; i < critical.size()-1; i++){
36            if(critical[i+1]-critical[i] < mini) mini = critical[i+1]-critical[i];
37        }
38        int maxi = critical.back()-critical[0];
39        return {mini, maxi};
40    }
41};