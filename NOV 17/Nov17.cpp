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
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        vector<int> inOrderResult; 
        vector<int> modes;        
        inOrderTraversal(root, inOrderResult);
        
        int maxFrequency = 0, currentFrequency = 0;
        int prev = inOrderResult[0];

        for (int num : inOrderResult) {
            if (num == prev) {
                currentFrequency++;
            } else {
                currentFrequency = 1;
            }

            if (currentFrequency > maxFrequency) {
                maxFrequency = currentFrequency;
                modes.clear();
                modes.push_back(num);
            } else if (currentFrequency == maxFrequency) {
                modes.push_back(num);
            }

            prev = num;
        }
        
        return modes;
    }

private:
    void inOrderTraversal(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inOrderTraversal(root->left, result);
        result.push_back(root->val);
        inOrderTraversal(root->right, result);
    }
};
