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
class BSTIterator {
public:
    vector<TreeNode* > in;
    int i;
    void inordertraversal(TreeNode* root){
        if(root == NULL) return;
        inordertraversal(root->left);
        in.push_back(root);
        inordertraversal(root->right);
        
    }
        
    
    BSTIterator(TreeNode* root) {
        inordertraversal(root);
        this->i = 0;
    }
    
    int next() {
        return in[i++]->val;
        
        // return -1;
        
    }
    
    bool hasNext() {
        return i < (in.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
