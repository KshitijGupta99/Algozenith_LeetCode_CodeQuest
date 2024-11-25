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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ln = head;
        int t = 0;
        ListNode* curr = head;
        while(curr !=nullptr){
            curr = curr->next;
            t++;
        }
        if(t <= n)return head->next;
        for(int i = 0; i  < t- n -1; i++){
            ln =  ln->next;
        }
        ListNode* nl = ln->next;
        if(nl == nullptr){
            return nullptr;
        }
        if(nl->next == nullptr){
            ln->next = nullptr;
        }else{
            ln->next = nl->next;
        }
        
        return head;
    }
};
