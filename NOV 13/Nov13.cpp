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
    TreeNode* CreateTree(vector<int>& nums, int l, int r){
        
        if (l >r) {
            return nullptr;
        }
        if(l == r){
            return new TreeNode(nums[l]);                    //for a single elemtent
        }
        int n = r-l +1;
        TreeNode* root = new TreeNode(nums[(l + r )/2]);
        root->left = CreateTree( nums, l, (l + r)/2 - 1);
        root->right = CreateTree( nums, (l + r )/2 + 1, r );
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = new TreeNode(nums[n/2]);           // creating the root node
        root->left = CreateTree( nums, 0, n/2 - 1);
        root->right = CreateTree( nums, n/2 + 1, n - 1);
        return root;
    }
};
