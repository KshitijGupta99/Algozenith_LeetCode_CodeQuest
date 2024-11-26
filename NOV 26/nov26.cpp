class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        while(l1!= nullptr && l2 !=nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 != nullptr) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        return res->next;
    }
};
