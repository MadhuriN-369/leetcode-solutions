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
13    ListNode* mergeKLists(vector<ListNode*>& lists) {
14        vector<int>arr;
15        for(int i = 0; i < lists.size(); i++) {
16            ListNode* temp = lists[i];
17            while(temp != NULL) {
18                arr.push_back(temp->val);
19                temp = temp->next;
20            }
21        }
22        sort(arr.begin(), arr.end());
23        ListNode* answer = new ListNode(0);
24        ListNode* tail = answer;
25        for(int i = 0; i < arr.size(); i++){
26            tail->next = new ListNode(arr[i]);
27            tail = tail->next;
28        }
29        return answer->next;
30    }
31};