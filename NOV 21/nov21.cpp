/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return NULL;
        if(head->next == nullptr) return new TreeNode(head->val);

        // ListNode* s = head;
        ListNode* f = head;
        ListNode* mid = head;
        ListNode* pv = nullptr;

        while(f != nullptr && f->next != nullptr){
            pv = mid;
            f = f->next;
            f = f->next;
            mid = mid->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->right = sortedListToBST(mid->next);
        if(pv != nullptr){
            pv ->next = nullptr;
        }
        // mid = NULL;
        root->left = sortedListToBST(head == mid ? nullptr : head);
        return root;

        
    }
};
