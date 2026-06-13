class Solution {
public:
ListNode* f(vector<ListNode*>& lists,int l,int r){
 if(l==r) return lists[l];
 int mid=l+(r-l)/2;
 ListNode* a=f(lists,l,mid);
 ListNode* b=f(lists,mid+1,r);
 ListNode* dummy=new ListNode(-1);
 ListNode* temp=dummy;
 while(a && b){
    if(a->val<b->val){
        temp->next=a;
        a=a->next;
    }else{
        temp->next=b;
        b=b->next;
    }
    temp=temp->next;
 }
 if(a) temp->next=a;
 if(b) temp->next=b;
 return dummy->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(lists.size() == 0) return NULL;
        return f(lists,0,k-1);
    }
};