class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // convert
        for(int i=0;i<n;i++){
            if(nums[i]==target) nums[i]=1;
            else nums[i]=-1;
        }

        vector<int> pref(n+1);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }

        // coordinate compress prefix
        vector<int> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto getID=[&](int x){
            return (int)(lower_bound(all.begin(),all.end(),x)-all.begin());
        };

        int sz = all.size();
        vector<int> seg(4*sz,0);

        function<void(int,int,int,int)> update = [&](int idx,int l,int r,int pos){
            if(l==r){
                seg[idx]++;
                return;
            }
            int mid=(l+r)/2;
            if(pos<=mid) update(idx*2,l,mid,pos);
            else update(idx*2+1,mid+1,r,pos);
            seg[idx]=seg[idx*2]+seg[idx*2+1];
        };

        function<int(int,int,int,int,int)> query=[&](int idx,int l,int r,int ql,int qr){
            if(ql>r||qr<l) return 0;
            if(ql<=l && r<=qr) return seg[idx];
            int mid=(l+r)/2;
            return query(idx*2,l,mid,ql,qr)+query(idx*2+1,mid+1,r,ql,qr);
        };

        long long res=0;

        // initial prefix 0 update
        update(1,0,sz-1,getID(pref[0]));

        for(int i=1;i<=n;i++){
            int id = getID(pref[i]);
            // count how many prefix < this
            if(id>0) res += query(1,0,sz-1,0,id-1);
            update(1,0,sz-1,id);
        }

        return (int)res;
    }
};