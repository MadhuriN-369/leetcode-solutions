1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int ans = 0;
15    pair<int,int>solve(TreeNode* node){
16        long long sum = node->val;
17        int count = 1;
18        if(node->left){
19            auto left = solve(node->left);
20            sum += left.first;
21            count += left.second;
22        }
23        if(node->right){
24            auto right = solve(node->right);
25            sum += right.first;
26            count += right.second;
27        }
28        if(count == 1) {
29            cout<<node->val<<endl;
30            ans++;
31            return {node->val, 1};
32        }
33        if(sum/(count) == node->val) {
34            cout<<node->val<<endl;
35            ans++;
36        }
37        return {sum, count};
38    }
39    int averageOfSubtree(TreeNode* root) {
40        auto temp = solve(root);
41        return ans;
42    }
43};