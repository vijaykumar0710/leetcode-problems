typedef long long int;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
       int n=nums2.size();
       int s=ceil(sqrt(n));
       vector<unordered_map<int,int>>blocks(s);
       vector<int>lazy(s,0);
       for(int i=0;i<n;i++){
        int b=i/s;
        blocks[b][nums2[i]]++;
       }
       vector<int>res;
       for(auto q:queries){
          if(q[0]==1){
            int l=q[1],r=q[2],val=q[3];
            int b_l=l/s,b_r=r/s;
            if(b_l==b_r){
                for(int i=l;i<=r;i++){
                    blocks[b_l][nums2[i]]--;
                    if(blocks[b_l][nums2[i]]==0) blocks[b_l].erase(nums2[i]);
                    nums2[i]+=val;
                    blocks[b_l][nums2[i]]++;
                }
            }else{
                int end=(b_l+1)*s-1;
                for(int i=l;i<=end;i++){
                    blocks[b_l][nums2[i]]--;
                    if(blocks[b_l][nums2[i]]==0) blocks[b_l].erase(nums2[i]);
                    nums2[i]+=(long long)val;
                    blocks[b_l][nums2[i]]++;
                }
                for(int i=b_l+1;i<b_r;i++) lazy[i]+=(long long)val;
                int st=b_r*s;
                for(int i=st;i<=r;i++){
                    blocks[b_r][nums2[i]]--;
                    if(blocks[b_r][nums2[i]]==0) blocks[b_r].erase(nums2[i]);
                    nums2[i]+=(long long)val;
                    blocks[b_r][nums2[i]]++;
                }
            }
          }else if(q[0]==2){
             int tot=q[1];
             int pairs=0;
           for(auto x:nums1){
            int tar=tot-x;
            for(int b=0;b<s;b++){
                int need=tar-lazy[b];
                if(blocks[b].count(need)) pairs+=blocks[b][need];
             }
           }
           res.push_back(pairs);
          }
       }
       return res;
    }
};