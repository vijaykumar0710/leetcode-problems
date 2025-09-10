class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        unordered_set<int>st;
        for(auto &fri:friendships){
            int u1=fri[0],u2=fri[1];
             auto lan_u1=languages[u1-1];
             auto lan_u2=languages[u2-1];
             bool flag=false;
             for(auto &x:lan_u1){
                for(auto &y:lan_u2){
                    if(x==y) flag=true; 
                }
             }
            if(!flag) st.insert(u1),st.insert(u2);
        }
        if(st.size()==0) return 0;
        int res=INT_MAX;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto &u:st){
            auto lan_u=languages[u-1];
            sort(lan_u.begin(),lan_u.end());
            auto it=lower_bound(lan_u.begin(),lan_u.end(),i);
            if(it==lan_u.end() || (it!=lan_u.end() && *it!=i)) cnt++; 
            }
            res=min(res,cnt);
        }
        return res;
    }
};