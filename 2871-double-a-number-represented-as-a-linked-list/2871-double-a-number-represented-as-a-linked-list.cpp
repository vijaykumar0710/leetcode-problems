class Solution {
public:
ListNode* reversedList(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* last=reversedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return last;
}
    ListNode* doubleIt(ListNode* head) {
        head=reversedList(head);
        int carry=0;
        ListNode* temp=head;
        ListNode* dummy=NULL;
        while(temp!=NULL){
            int x=2*temp->val+carry;
            temp->val=x%10;
            carry=x/10;
            // if(x>=10){
            //     carry=1;
            // }else carry=0;
            dummy=temp;
            temp=temp->next;
        }
        if(carry!=0){
            dummy->next=new ListNode(carry);
            dummy=dummy->next;
        }
        return reversedList(head);
    }
};