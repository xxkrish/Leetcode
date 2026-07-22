/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int currDepth, int &maxDepth){

        if(root == NULL){
            return;
        }
        currDepth++;
        dfs(root->left, currDepth, maxDepth);
        dfs(root->right, currDepth, maxDepth);
        maxDepth = max(maxDepth, currDepth);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int currDepth = 0; 
        int maxDepth = 0;

       dfs(root, currDepth, maxDepth);

       return maxDepth;

    }
};