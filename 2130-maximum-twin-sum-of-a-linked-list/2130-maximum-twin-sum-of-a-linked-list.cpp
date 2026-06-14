class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=s;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* s1=head;
        ListNode* pt=prev;
        int maxi=0;
        while(pt){
            maxi=max(maxi,s1->val+pt->val);
            s1=s1->next;
            pt=pt->next;
        }
        return maxi;
    }
};