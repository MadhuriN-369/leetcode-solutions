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
11    bool hasCycle(ListNode *head) {
12        unordered_set<ListNode*>st;
13        ListNode*temp = head;
14        while(temp != nullptr) {
15            if(st.find(temp) != st.end()){
16                return true;
17            }
18            st.insert(temp);
19            temp = temp->next;
20        }
21        return false;
22    }
23};