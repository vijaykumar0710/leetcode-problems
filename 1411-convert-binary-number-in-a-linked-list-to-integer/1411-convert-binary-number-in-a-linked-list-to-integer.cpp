class Solution {
public:
void solve(ListNode* head,vector<int>&vec){
    if(head==NULL) return;
    solve(head->next,vec);
    vec.push_back(head->val);
}
    int getDecimalValue(ListNode* head) {
        vector<int>vec;
        solve(head,vec);
        int res=0;
       int n= vec.size();
        for(int i=0;i<n;i++){
            res+=(vec[i]*pow(2,i));
        }
        return res;
    }
};