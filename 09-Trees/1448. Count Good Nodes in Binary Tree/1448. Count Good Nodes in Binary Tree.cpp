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
14    int count = 0;
15    void dfs(TreeNode* root, int maxi){
16        if(root == nullptr) return;
17        if(root->val >= maxi){
18            maxi = root->val;
19            count++;
20        }
21        if(root->left != nullptr) dfs(root->left, maxi);
22        if(root->right != nullptr) dfs(root->right, maxi);
23    }
24    int goodNodes(TreeNode* root) {
25        dfs(root, -10001);
26        return count;
27    }
28};