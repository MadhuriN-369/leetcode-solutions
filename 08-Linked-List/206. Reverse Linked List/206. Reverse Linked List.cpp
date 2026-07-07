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
13    ListNode* reverseList(ListNode* head) {
14        vector<int>arr;
15        ListNode* temp = head;
16        while(temp){
17            arr.push_back(temp->val);
18            temp = temp->next;
19        }
20        reverse(arr.begin(), arr.end());
21        temp = head;
22        for(auto it: arr){
23            temp->val = it;
24            temp = temp->next;
25        }
26        return head;
27    }
28};