// Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        int flag = 0;
        while (root){
            if (root->val == val){
                flag = 1;
                break;
            }
            else if (val > root->val)
                root = root->right;
            else
                root = root->left;
        }
        if (flag)
            return root;
        return NULL;
    }
};
/**
Runtime: 32 ms, faster than 97.40% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 34.8 MB, less than 78.33% of C++ online submissions for Search in a Binary Search Tree.
*/


// Recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (val == root->val)
            return root;
        if (val > root->val)
            return (root->right==NULL)? NULL: searchBST(root->right, val);
        else
            return (root->left==NULL)? NULL : searchBST(root->left, val);
    }
};
/**
Runtime: 36 ms, faster than 92.19% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 34.8 MB, less than 54.81% of C++ online submissions for Search in a Binary Search Tree.
*/
