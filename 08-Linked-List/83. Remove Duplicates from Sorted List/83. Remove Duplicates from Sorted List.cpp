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
13    ListNode* deleteDuplicates(ListNode* head) {
14        if(!head || !head->next) return head;
15        ListNode* prev = head;
16        ListNode* temp = head->next;
17        while(temp){
18            if(temp->val == prev->val){
19                prev->next = temp->next;
20                temp = temp->next;
21            }
22            else{
23                prev = temp;
24                temp = temp->next;
25            }
26            
27        }
28        return head;
29    }
30};