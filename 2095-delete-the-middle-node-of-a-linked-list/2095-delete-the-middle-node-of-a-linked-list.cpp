class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* s=head;
        ListNode* f=head;
        while(f->next->next && f->next->next->next){
            s=s->next;
            f=f->next->next;
        }
        s->next=s->next->next;
        return head;
    }
};