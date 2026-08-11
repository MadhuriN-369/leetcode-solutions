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
14        if(head == nullptr || head->next == nullptr) return head;
15        ListNode* cur = head, *prev = nullptr, *next = head->next;
16        while(cur != nullptr){
17            ListNode*temp = cur;
18            next = cur->next;
19            cur->next = prev;
20            prev = temp;
21            cur = next;
22        }
23        return prev;
24    }
25};