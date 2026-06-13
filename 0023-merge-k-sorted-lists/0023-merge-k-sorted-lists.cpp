class Solution {
public:
ListNode* f(ListNode* a,ListNode* b){
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
        if(lists.size() == 0) return NULL;
        ListNode* res=lists[0];
        for(auto i=1;i<lists.size();i++){
            res=f(lists[i],res);
        }
        return res;
    }
};