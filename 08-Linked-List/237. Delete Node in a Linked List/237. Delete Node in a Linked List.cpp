1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    void deleteNode(ListNode* node) {
12        ListNode* temp = node, *prev = nullptr;
13        while(temp->next != NULL){
14            temp->val = temp->next->val;
15            prev = temp;
16            temp = temp->next;
17        }
18        prev->next = NULL;
19    }
20};