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
13    ListNode* reverse(ListNode* head, ListNode* prev){
14        if(head == nullptr) return prev;
15        ListNode* temp = head, *next = head->next;
16        temp->next = prev;
17        return reverse(next, temp);
18    }
19    ListNode* reverseList(ListNode* head) {
20        return reverse(head, nullptr);
21    }
22};