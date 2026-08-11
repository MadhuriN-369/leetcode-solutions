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
14        if(head == nullptr || head->next == nullptr) return head;
15        ListNode *odd = head, *evenHead = head->next, *even = evenHead;
16
17        while(even != nullptr && even->next != nullptr){
18            odd->next = odd->next->next;
19            even->next = even->next->next;
20            odd = odd->next;
21            even = even->next;
22        }
23        odd->next = evenHead;
24        return head;
25    }
26};