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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return false;
        if(sameTree(root, subRoot)) return true;
        return isSubtree(root ->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool sameTree(TreeNode* node, TreeNode* subRoot){
        if(node==nullptr && subRoot==nullptr){
            return true;
        }
        if(node && subRoot && node->val == subRoot->val){
            return sameTree(node->left, subRoot->left) && sameTree(node->right,subRoot->right);
        }
        return false;
    }
};
