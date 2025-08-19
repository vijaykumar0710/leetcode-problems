class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* t=head;
        while(t){
          n++;
          t=t->next;
        }
        if(n>0)k=k%n;
        if(k==0 || n==0) return head;
         ListNode* temp=head;
         while(temp->next) temp=temp->next;

         temp->next=head;

         int limit=n-k-1;
         ListNode* temp1=head;
         while(limit--) temp1=temp1->next;

         head=temp1->next;
         temp1->next=NULL;

         return head;
    }
};