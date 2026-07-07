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
14        if(!head || !head->next) return head;
15        ListNode* prev = nullptr, *cur = head, *next = head->next;
16        while(cur){
17            next = cur->next;
18            
19            
20            cur->next = prev;
21            prev = cur;
22            cur = next;
23        }
24        return prev;
25    }
26};