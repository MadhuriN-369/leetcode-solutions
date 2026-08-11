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
13    ListNode* oddEvenList(ListNode* head) {
14        vector<int>arr;
15        ListNode*temp = head;
16        while(temp != nullptr){
17            arr.push_back(temp->val);
18            temp = temp->next;
19        }
20        temp = head;
21        int i = 0;
22        while(i < arr.size()){
23            temp->val = arr[i];
24            i += 2;
25            temp = temp->next;
26        }
27        i = 1;
28        while(i < arr.size()){
29            temp->val = arr[i];
30            i += 2;
31            temp = temp->next;
32        }
33        return head;
34    }
35};