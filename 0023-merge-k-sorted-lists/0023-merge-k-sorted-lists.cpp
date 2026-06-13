class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto x:lists) if(x) pq.push({x->val,x});
        ListNode* dummy=new ListNode(-1);
        ListNode* it=dummy;
        while(!pq.empty()){
          it->next=pq.top().second;
          if(pq.top().second->next) pq.push({pq.top().second->next->val,pq.top().second->next});
          pq.pop();
          it=it->next;
        } 
        return dummy->next;
    }
};